<template>
  <q-page id="tv">
    <q-btn :disabled="notMapped('power')" round color="negative" size="2vh" icon="power_settings_new" class="power" v-on:click="buttonPressed('power')" />
    <button :disabled="notMapped('tv')" tabindex="0" type="button" v-on:click="buttonPressed('tv')" class="q-btn inline relative-position q-btn-item non-selectable power q-btn-round q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;float: right">
      <div class="q-btn-inner row col items-center justify-center">TV</div>
    </button>
    <br/>
    <q-btn :disabled="notMapped('caption')" color="dark" size="2vh" class="small-1" label="caption" v-on:click="buttonPressed('caption')" />
    <q-btn :disabled="notMapped('help')" color="dark" size="2vh" class="small-1" icon="help" v-on:click="buttonPressed('help')" />
    <q-btn :disabled="notMapped('search')" color="dark" size="2vh" class="small-1" icon="search" v-on:click="buttonPressed('search')" />
    <q-btn :disabled="notMapped('home')" color="dark" size="2vh" class="small-1" icon="home" v-on:click="buttonPressed('home')" />

    <q-btn :disabled="notMapped('n1')" color="dark" size="3vh" label="1" class="number" v-on:click="buttonPressed('n1')" />
    <q-btn :disabled="notMapped('n2')" color="dark" size="3vh" label="2" class="number" v-on:click="buttonPressed('n2')" />
    <q-btn :disabled="notMapped('n3')" color="dark" size="3vh" label="3" class="number" v-on:click="buttonPressed('n3')" />
    <q-btn :disabled="notMapped('n4')" color="dark" size="3vh" label="4" class="number" v-on:click="buttonPressed('n4')" />
    <q-btn :disabled="notMapped('n5')" color="dark" size="3vh" label="5" class="number" v-on:click="buttonPressed('n5')" />
    <q-btn :disabled="notMapped('n6')" color="dark" size="3vh" label="6" class="number" v-on:click="buttonPressed('n6')" />
    <q-btn :disabled="notMapped('n7')" color="dark" size="3vh" label="7" class="number" v-on:click="buttonPressed('n7')" />
    <q-btn :disabled="notMapped('n8')" color="dark" size="3vh" label="8" class="number" v-on:click="buttonPressed('n8')" />
    <q-btn :disabled="notMapped('n9')" color="dark" size="3vh" label="9" class="number" v-on:click="buttonPressed('n9')" />
    <q-btn :disabled="notMapped('list')" color="dark" size="2vh" label="list" class="number" v-on:click="buttonPressed('list')" />
    <q-btn :disabled="notMapped('n0')" color="dark" size="3vh" label="0" class="number" v-on:click="buttonPressed('n0')" />
    <q-btn :disabled="notMapped('flashbk')" color="dark" size="2vh" label="flashbk" class="number" v-on:click="buttonPressed('flashbk')" />

    <div style="width:33%;float:left">
      <q-btn :disabled="notMapped('volp')" color="blue-grey" size="3vh" label="Vol" icon-right="add" class="lg-in" v-on:click="buttonPressed('volp')" />
      <q-btn :disabled="notMapped('volm')" color="blue-grey" size="3vh" label="Vol" icon-right="remove" class="lg-in" v-on:click="buttonPressed('volm')" />
    </div>
    <div style="width:33%;float:left">
      <q-btn :disabled="notMapped('fav')" color="dark" size="2vh" label="fav" class="sm-in" v-on:click="buttonPressed('fav')" />
      <q-btn :disabled="notMapped('info')" color="dark" size="2vh" label="info" class="sm-in" v-on:click="buttonPressed('info')" />
      <q-btn :disabled="notMapped('mute')" color="dark" size="2vh" label="mute" class="sm-in" v-on:click="buttonPressed('mute')" />
    </div>
    <div style="width:33%;float:left">
      <q-btn :disabled="notMapped('chp')" color="blue-grey" size="3vh" label="Ch" icon-right="add" class="lg-in" v-on:click="buttonPressed('chp')" />
      <q-btn :disabled="notMapped('chm')" color="blue-grey" size="3vh" label="Ch" icon-right="remove" class="lg-in" v-on:click="buttonPressed('chm')"/>
    </div>

    <q-btn :disabled="notMapped('settings')" color="blue-grey" size="2vh" icon="settings" class="number" v-on:click="buttonPressed('settings')" />
    <q-btn :disabled="notMapped('up')" color="blue-grey" size="3vh" icon="arrow_drop_up" class="number" v-on:click="buttonPressed('up')" />
    <q-btn :disabled="notMapped('livezoom')" color="blue-grey" size="2vh" label="livezoom" class="number" v-on:click="buttonPressed('livezoom')" />
    <q-btn :disabled="notMapped('left')" color="blue-grey" size="3vh" icon="arrow_left" class="number" v-on:click="buttonPressed('left')" />
    <q-btn :disabled="notMapped('ok')" color="black" size="3vh" icon="my_location" class="number" v-on:click="buttonPressed('ok')" />
    <q-btn :disabled="notMapped('right')" color="blue-grey" size="3vh" icon="arrow_right" class="number" v-on:click="buttonPressed('right')" />
    <q-btn :disabled="notMapped('back')" color="blue-grey" size="2vh" label="back" class="number" v-on:click="buttonPressed('back')" />
    <q-btn :disabled="notMapped('down')" color="blue-grey" size="3vh" icon="arrow_drop_down" class="number" v-on:click="buttonPressed('down')" />
    <q-btn :disabled="notMapped('exit')" color="blue-grey" size="2vh" label="exit" class="number" v-on:click="buttonPressed('exit')" />

    <q-btn :disabled="notMapped('sap')" color="blue-grey" size="2vh" label="sap/*" class="number" v-on:click="buttonPressed('sap')" />
    <q-btn :disabled="notMapped('sleep')" color="blue-grey" size="2vh" label="sleep" class="number" v-on:click="buttonPressed('sleep')" />
    <q-btn :disabled="notMapped('stop')" color="blue-grey" size="2vh" icon="stop" class="number" v-on:click="buttonPressed('stop')" />

    <q-btn :disabled="notMapped('rewind')" color="dark" size="2vh" class="small-1" icon="fast_rewind" v-on:click="buttonPressed('rewind')" />
    <q-btn :disabled="notMapped('play')" color="dark" size="2vh" class="small-1" icon="play_arrow" v-on:click="buttonPressed('play')" />
    <q-btn :disabled="notMapped('pause')" color="dark" size="2vh" class="small-1" icon="pause" v-on:click="buttonPressed('pause')" />
    <q-btn :disabled="notMapped('forward')" color="dark" size="2vh" class="small-1" icon="fast_forward" v-on:click="buttonPressed('forward')" />

    <q-btn :disabled="notMapped('point1')" color="red" size="2vh" class="small-1" icon="fiber_manual_record" v-on:click="buttonPressed('point1')" />
    <q-btn :disabled="notMapped('point2')" color="green" size="2vh" class="small-1" icon="fiber_manual_record" v-on:click="buttonPressed('point2')" />
    <q-btn :disabled="notMapped('point3')" color="yellow" size="2vh" class="small-1" icon="fiber_manual_record" v-on:click="buttonPressed('point3')" />
    <q-btn :disabled="notMapped('point4')" color="blue" size="2vh" class="small-1" icon="fiber_manual_record" v-on:click="buttonPressed('point4')" />

    <q-modal v-model="opened" minimized content-css="padding: 20px">
      <p>{{configurandoMsg}}</p>
      <q-btn
        color="primary"
        @click="opened = false"
        label="Sair"
      />
    </q-modal>

  </q-page>
</template>

<script>
import SpeechMixin from '../../components/SpeechMixin'

export default {
  data () {
    return {
      configurandoMsg: '',
      opened: false,
      btn: {},
      key: null
    }
  },
  mixins: [SpeechMixin],
  methods: {
    buttonPressed: function (key) {
      // step 1
      this.configurandoMsg = 'Configurando voz para botão [' + key + ']... aguardando voz...'
      this.opened = true
      this.speechStart()
      this.key = key
    },
    getControlsConfig: function () {
      this.$axios.get('https://' + location.hostname + ':3000/cfg/control/tv', {control: 'tv'})
        .then((response) => {
          this.btn = response.data.control.button
        })
        .catch((e) => {
          console.log('error', e)
        })
    },
    notMapped: function (btnLabel) {
      return !(this.btn[btnLabel] && this.btn[btnLabel].length > 0)
    },
    speechResultCommand: function (command) {
      console.log(command)
      this.$axios.get('https://' + location.hostname + ':3000/calibrar-voz/tv/' + this.key + '/' + command, {})
        .then((response) => {
          console.log(response)
          this.opened = false
        })
        .catch((e) => {
          console.log('error', e)
          this.opened = false
        })
    }
  },
  mounted: function () {
    this.getControlsConfig()
    this.$root.$on('speechResult', (command) => {
      if (command === 'error') {
        this.opened = false
        return
      }
      this.speechResultCommand(command)
    })
  }
}
</script>

<style lang="stylus">
#tv
  padding 6px 10px

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
