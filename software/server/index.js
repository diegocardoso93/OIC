const Koa = require('koa')
const Router = require('koa-router')
const app = new Koa()
const router = new Router()
const cors = require('@koa/cors');

const mqtt = require('mqtt')

const client  = mqtt.connect('mqtt://localhost')

client.on('connect', () => {
  client.subscribe('write/temperature', (err) => {})
})

// Begin periodic calls
let state = {
  temperature: null
}
setInterval(() => {
  client.publish('read/temperature', null) // Later, broker will publish on topic write/temperature
}, 10000);

client.on('message', (topic, message) => {
  console.log(message.toString())
  if (topic == 'write/temperature') {
    sensor.temperature = message.toString();
  }
  client.end()
})

router.get('/', (ctx, next) => {
  ctx.body = 'hello'
})

router.get('/read/temperature', (ctx, next) => {
  ctx.body = {status: 200, temperature: state.temperature}
})

router.get('/tv/:button', (ctx, next) => {
  client.publish('control/tv', ctx.params.button)
  ctx.body = {status: 200}
})

router.get('/split/:button', (ctx, next) => {
  client.publish('control/split', ctx.params.button)
  ctx.body = {status: 200}
})

app
  .use(cors({origin: (ctx) => { return '*' }}))
  .use(router.routes())

app.listen(3000)
