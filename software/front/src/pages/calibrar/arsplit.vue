<template>
  <q-page id="split">
    <div style="width: 100%; text-align: center">
      <div class="temp_container">
        <h1 style="margin: 10px" v-text="temperatura"></h1>
      </div>
    </div>
    <q-btn round color="blue" size="3vh" icon="power_settings_new" class="power" v-on:click="buttonPressed('power')" />
    <button tabindex="0" type="button" v-on:click="buttonPressed('mode')" class="q-btn inline relative-position q-btn-item non-selectable power q-btn-round q-focusable q-hoverable bg-positive text-white" style="font-size: 3vh;float: right">
      <div class="q-btn-inner row col items-center justify-center">mode</div>
    </button>
    <br/>
    <q-btn color="light" size="3vh" label="sleep" class="number" v-on:click="buttonPressed('sleep')" />
    <q-btn color="light" size="3vh" icon="arrow_drop_up" class="number" v-on:click="buttonPressed('up')" />
    <q-btn color="light" size="3vh" label="fan" class="number" v-on:click="buttonPressed('fan')" />
    <q-btn color="light" size="3vh" label="timer" class="number" v-on:click="buttonPressed('timer')" />
    <q-btn color="light" size="3vh" icon="arrow_drop_down" class="number" v-on:click="buttonPressed('down')" />
    <q-btn color="light" size="3vh" label="swing" class="number" v-on:click="buttonPressed('swing')" />

    <q-modal v-model="opened" minimized content-css="padding: 20px">
      <p>Calibrando botão [{{btnCalibrando}}]... aguardando comando...</p>
      <q-btn
        color="primary"
        @click="opened = false"
        label="Sair"
      />
    </q-modal>

  </q-page>
</template>

<script>
export default {
  data () {
    return {
      temperatura: '',
      btnCalibrando: '',
      opened: false
    }
  },
  methods: {
    buttonPressed: function (key) {
      this.btnCalibrando = key
      this.opened = true
      this.$axios.get('https://' + location.hostname + ':3000/calibrate/split/' + key)
        .then((response) => {
          console.log(response)
          this.opened = false
          this.btnCalibrando = ''
        })
        .catch((e) => {
          this.opened = false
          this.btnCalibrando = ''
          console.log('error', e)
        })
    },
    readTemperature: function () {
      this.$axios.get('https://' + location.hostname + ':3000/read/temperatura')
        .then((response) => {
          if (response.status === 200) {
            this.temperatura = response.data.temperatura + '°C'
          }
        })
        .catch(() => {
          console.log('error on read temperature')
        })
    }
  },
  mounted () {
    this.readTemperature()
    this.readTempControl = setInterval(() => {
      this.readTemperature()
    }, 5000)
  },
  destroyed () {
    clearInterval(this.readTempControl)
  }
}
</script>

<style lang="stylus">
#split
  padding 6px 10px
  background-color #eaeaea

#split
  .q-btn-inner
    color #000

.temp_container
  width 60%
  background-color #fff
  text-align center
  margin auto

.power
  margin 2%

.number
  margin 2% 2%
  width 29%
  padding 0

.lg-in
  margin 5% 6%
  padding 0
  width 88%

.sm-in
  margin 3% 5%
  width 90%

.small-1
  margin 2% 2%
  width 20.8%

</style>
