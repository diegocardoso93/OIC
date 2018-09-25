const Koa = require('koa')
const Router = require('koa-router')
const app = new Koa()
const router = new Router()
const cors = require('@koa/cors');
const mqtt = require('mqtt')

const db = require('mongo');

const dgn = require('./dragonboard-native')
const IRcontrols = require('./ir-control-templates')

// Store key current button calibrating
let calibrating = {
  control: '', // sample: tv
  button: '',   // sample: power
  active: false
}

// @todo read db 4 IRcontrols
// --
db.mgFind(db.oic, 'IRcontrols', {}, (data) => {
console.log(data)
})
db.mgClient.close();

const client  = mqtt.connect('mqtt://localhost')

client.on('connect', () => {
  // client.subscribe('write/temperatura', (err) => {})
  client.subscribe('calibrate', (err) => {})
})

client.on('message', (topic, message) => {
  console.log(message.toString())
  if (topic == 'calibrate' && calibrating.active) {
    // @todo read db
    IRcontrols[calibrating.control]
              [calibrating.button] = message.toString();
    // @todo save db
    calibrating.active = false
  }
  client.end()
})

router.get('/', (ctx, next) => {
  ctx.body = 'hello'
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
router.get('/cfg/control', (ctx, next) => {
  ctx.body = {status: 200, control: IRcontrols}
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
  client.publish('control/tv', ctx.params.button)
  ctx.body = {status: 200}
})

router.get('/split/:button', (ctx, next) => {
  client.publish('control/split', ctx.params.button)
  ctx.body = {status: 200}
})

router.get('/iluminacao/:button', (ctx, next) => {
  client.publish('control/iluminacao', ctx.params.button)
  ctx.body = {status: 200}
})

router.get('/receptor-tv/:button', (ctx, next) => {
  client.publish('control/receptor-tv', ctx.params.button)
  ctx.body = {status: 200}
})
// -------

app
  .use(cors({origin: (ctx) => { return '*' }}))
  .use(router.routes())

app.listen(3000, '0.0.0.0')
