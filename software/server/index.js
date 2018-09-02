const Koa = require('koa')
const Router = require('koa-router')
const app = new Koa()
const router = new Router()
const cors = require('@koa/cors');

const mqtt = require('mqtt')

const client  = mqtt.connect('mqtt://localhost')

client.on('connect', function () {
  client.subscribe('presence', function (err) {})
})
 
client.on('message', function (topic, message) {
  console.log(message.toString())
  client.end()
})

router.get('/', (ctx, next) => {
  ctx.body = 'hello'
})

router.get('/tv/:button', (ctx, next) => {
  client.publish('control/tv', ctx.params.button)
  ctx.body = {status: 200}
})

app
  .use(cors({origin: (ctx) => { return '*' }}))
  .use(router.routes())

app.listen(3000)
