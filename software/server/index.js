const https = require('https')
const fs = require('fs')
const Koa = require('koa')
const Router = require('koa-router')
const app = new Koa()
const router = new Router()
const cors = require('@koa/cors')
const mqtt = require('mqtt')

const db = require('./mongo')

const dgn = require('./dragonboard-native')
let IRcontrols = require('./ir-control-templates')

// Store key current button calibrating
let calibrating = {
  control: '', // sample: tv
  button: '',   // sample: power
  active: false
}

db.mgConnect((oic, mgClient) => {
  db.mgFind(oic, 'IRcontrols', {}, (data) => {
    if (data.length == 0) { // First time
      db.mgInsert(oic, 'IRcontrols', IRcontrols, () => {})
    } else {
      IRcontrols = data
    }
  })

  const client  = mqtt.connect('mqtt://localhost')

  client.on('connect', () => {
    // client.subscribe('write/temperatura', (err) => {})
    client.subscribe('calibrate', (err) => {})
  })

  client.on('message', (topic, message) => {
    console.log(topic, message.toString())
    //client.end()
  })

  router.get('/', (ctx, next) => {
    ctx.body = 'hello'
  })
  router.get('/meta/IRcontrols', (ctx, next) => {
    ctx.body = IRcontrols
  })

  // Entering calibrate state
  router.get('/calibrate/:control/:button', (ctx, next) => {
      calibrating = {
        control: ctx.params.control,
        button: ctx.params.button,
        active: true
      }
      setTimeout(() => {
        calibrating.active = false
      }, 30000)

    return new Promise((resolve, reject) => {
      dgn.call('ir_receiver').then((message) => {
        let objSet = {}
        objSet['button.'+calibrating.button] = message.toString()
        db.mgUpdate(oic, 'IRcontrols', {name:calibrating.control}, objSet, (res) => {})
        calibrating.active = false
        db.mgFind(oic, 'IRcontrols', {}, (data) => {
          IRcontrols = data
        })
        ctx.body = {status: 200}
        resolve()
      })
    })
  })

  // Pooling/get control configs
  router.get('/cfg/control/:control', (ctx, next) => {
    return new Promise((resolve, reject) => {
      db.mgFind(oic, 'IRcontrols', {name: ctx.params.control}, (data) => {
        ctx.body = {status: 200, control: data[0]}
        resolve()
      })
    })
  })

  // Feed calibrate state
  router.get('/feed/calibrate', (ctx, next) => {
    ctx.body = {active: calibrating.active, control: IRcontrols}
  })

  router.get('/read/temperatura', (ctx, next) => {
    return new Promise((resolve, reject) => {
        dgn.call('temperature').then((data) => {
          ctx.body = {status: 200, temperatura: data.toString('utf8')}
          resolve()
        })
    })
  })


  let sendNEC = (control, button) => {
    db.mgFind(oic, 'IRcontrols', {name: control}, (data) => {
      client.publish('control/'+control, data[0]['button'][button])
      db.mgInsert(oic, 'IRlogs', [{
        control: control,
        button: button,
        date: new Date()
      }])
    })
  }

  router.get('/calibrar-voz/:control/:button/:command', (ctx, next) => {
    let p = ctx.params
    let objSelect = {'name': p.control, 'voice.btn': p.button}
    let objSet = {'voice.$.cmd': p.command}
    db.mgUpdate(oic, 'IRcontrols', objSelect, objSet, (res) => {})
    db.mgFind(oic, 'IRcontrols', {}, (data) => {
      IRcontrols = data
    })
    console.log(ctx.params.control, ctx.params.button, ctx.params.command)
    ctx.body = {status: 200}
  })

  router.get('/voice-command/:cmd', (ctx, next) => {
    let p = ctx.params
    db.mgFind(oic, 'IRcontrols', {'voice.cmd': p.cmd}, (data) => {
      if (data.length && data[0]['voice'].length) {
        sendNEC(data[0]['name'], data[0]['voice'][0]['btn'])
      }
    }, {projection: {'name': 1,'voice.$': 1}})
    ctx.body = {status: 200}
  })

  // --------
  // @BUTTON PRESS ACTIONS
  //
  router.get('/tv/:button', (ctx, next) => {
    sendNEC('tv', ctx.params.button)
    ctx.body = {status: 200}
  })

  router.get('/split/:button', (ctx, next) => {
    sendNEC('split', ctx.params.button)
    ctx.body = {status: 200}
  })

  router.get('/light/:button', (ctx, next) => {
    sendNEC('light', ctx.params.button)
    ctx.body = {status: 200}
  })

  router.get('/receptor-tv/:button', (ctx, next) => {
    sendNEC('receptor-tv', ctx.params.button)
    ctx.body = {status: 200}
  })
  // -------


  // ----
  // @LOG entries
  //
  router.get('/stats/control-use', (ctx, next) => {
       return new Promise((resolve, reject) => {
      db.mgAggregate(oic, 'IRlogs',
      [{
        $group: {
          _id: "$control",
          count: { $sum: 1 }
        }
      }], (res) => {
        ctx.body = {status: 200, graph: res}
        resolve()
      })
    })
  })

  router.get('/stats/control-button', (ctx, next) => {
       return new Promise((resolve, reject) => {
      db.mgAggregate(oic, 'IRlogs',
        [{ $group: { _id: {control: "$control", button: "$button"}, count: {$sum:1} }},
         {$group: { _id: {control: "$_id.control"},
           buttons: {$push: {button:"$_id.button", count:"$count"}}}
        }], (res) => {
        ctx.body = {status: 200, graph: res}
        resolve()
      })
    })
  })


const HOST = '0.0.0.0'
const HTTPS_PORT = 3000
const options = {
    key: fs.readFileSync('./ssl/host.key', 'utf8'),
    cert: fs.readFileSync('./ssl/host.cert', 'utf8')
}

  app
    .use(cors({origin: (ctx) => { return '*' }}))
    .use(router.routes())

const httpsServer = https.createServer(options, app.callback())
  .listen(HTTPS_PORT, HOST)

  //app.listen(3000, '0.0.0.0')


});
