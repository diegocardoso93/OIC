const Koa = require('koa')
const Router = require('koa-router')
const app = new Koa()
const router = new Router()
const cors = require('@koa/cors');
const dgn = require('./dragonboard-native')

const mqtt = require('mqtt')

const client  = mqtt.connect('mqtt://localhost')

client.on('connect', () => {
  // client.subscribe('write/temperatura', (err) => {})
})

client.on('message', (topic, message) => {
  console.log(message.toString())
  if (topic == 'write/temperatura') {
    sensor.temperatura = message.toString();
  }
  client.end()
})

router.get('/', (ctx, next) => {
  ctx.body = 'hello'
})

router.get('/read/temperatura', (ctx, next) => {
  return new Promise((resolve, reject) => {
       dgn.call('temperature').then((data) => {
       ctx.body = {status: 200, temperatura: data.toString('utf8')}
       resolve()
     })
  })
})

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

app
  .use(cors({origin: (ctx) => { return '*' }}))
  .use(router.routes())

app.listen(3000, '0.0.0.0')
