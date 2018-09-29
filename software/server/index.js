const Koa = require('koa')
const Router = require('koa-router')
const app = new Koa()
const router = new Router()
const cors = require('@koa/cors');
const mqtt = require('mqtt')

const db = require('./mongo');

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
    if (topic == 'calibrate' && calibrating.active) {
      let objSet = {}
      objSet["button."+calibrating.button] = message.toString()
      db.mgUpdate(oic, 'IRcontrols', {name:calibrating.control}, objSet, (res) => console.log(res))
      calibrating.active = false
      db.mgFind(oic, 'IRcontrols', {}, (data) => {
        IRcontrols = data
      })
    }
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
    ctx.body = {status: 200}
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


  // --------
  // @BUTTON PRESS ACTIONS
  //
  router.get('/tv/:button', (ctx, next) => {
    db.mgFind(oic, 'IRcontrols', {name: 'tv'}, (data) => {
      client.publish('control/tv', data[0]['button'][ctx.params.button])
    })
    ctx.body = {status: 200}
  })

  router.get('/split/:button', (ctx, next) => {
    db.mgFind(oic, 'IRcontrols', {name: 'split'}, (data) => {
      client.publish('control/split', data[0]['button'][ctx.params.button])
    })
    ctx.body = {status: 200}
  })

  router.get('/iluminacao/:button', (ctx, next) => {
    db.mgFind(oic, 'IRcontrols', {name: 'light'}, (data) => {
      client.publish('control/light', data[0]['button'][ctx.params.button])
    })
    ctx.body = {status: 200}
  })

  router.get('/receptor-tv/:button', (ctx, next) => {
    db.mgFind(oic, 'IRcontrols', {name: 'receptor-tv'}, (data) => {
      client.publish('control/receptor-tv', data[0]['button'][ctx.params.button])
    })
    ctx.body = {status: 200}
  })
  // -------


  // ----
  // @LOG entries
  //
  router.get('/log/:control/:button', (ctx, next) => {
    // ctx.params.control,
    // ctx.params.button,
    ctx.body = {status: 200}
  })

  app
    .use(cors({origin: (ctx) => { return '*' }}))
    .use(router.routes())

  app.listen(3000, '0.0.0.0')


});
