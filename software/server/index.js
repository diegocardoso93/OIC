const Koa = require('koa')
const Router = require('koa-router')
const app = new Koa()
const router = new Router()
const cors = require('@koa/cors');

const mqtt = require('mqtt')

const client  = mqtt.connect('mqtt://localhost')

client.on('connect', () => {
  client.subscribe('write/temperatura', (err) => {})
})

// Begin periodic calls
let state = {
  temperatura: null
}
setInterval(() => {
  client.publish('read/temperatura', null) // Mais tarde o broker irá fazer publish no topic write/temperatura
}, 10000);

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
  ctx.body = {status: 200, temperatura: state.temperatura}
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

app.listen(3000)
