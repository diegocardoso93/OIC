<template>
  <q-page id="receptor-tv">
    <q-btn :disabled="notMapped('power')" round color="negative" size="2vh" icon="power_settings_new" class="power" v-on:click="buttonPressed('power')" />
    <q-btn :disabled="notMapped('power_tv')" round color="dark" size="2vh" icon="power_settings_new" class="power" style="float: right" v-on:click="buttonPressed('power_tv')" />
    <br/>

    <button :disabled="notMapped('set_tv')" tabindex="0" type="button" v-on:click="buttonPressed('set_tv')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">SET</div>
    </button>
    <button :disabled="notMapped('tv_in')" tabindex="0" type="button" v-on:click="buttonPressed('tv_in')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">TV IN</div>
    </button>
    <button :disabled="notMapped('volm_tv')" tabindex="0" type="button" v-on:click="buttonPressed('volm_tv')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">VOL-</div>
    </button>
    <button :disabled="notMapped('volp_tv')" tabindex="0" type="button" v-on:click="buttonPressed('volp_tv')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">VOL+</div>
    </button>

    <button :disabled="notMapped('setup')" tabindex="0" type="button" v-on:click="buttonPressed('setup')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-red text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">SETUP</div>
    </button>
    <button :disabled="notMapped('app')" tabindex="0" type="button" v-on:click="buttonPressed('app')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-green text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">APP</div>
    </button>
    <button :disabled="notMapped('volm')" tabindex="0" type="button" v-on:click="buttonPressed('volm')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-yellow text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">VOL-</div>
    </button>
    <button :disabled="notMapped('volp')" tabindex="0" type="button" v-on:click="buttonPressed('volp')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-blue text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">VOL+</div>
    </button>

    <q-btn :disabled="notMapped('home')" round color="dark" size="2vh" icon="home" v-on:click="buttonPressed('home')" style="margin: 11%;"/>
    <q-btn :disabled="notMapped('up')" color="blue-grey" size="3vh" icon="arrow_drop_up" class="number" v-on:click="buttonPressed('up')" />
    <q-btn :disabled="notMapped('repeat')" round color="dark" size="2vh" icon="repeat" v-on:click="buttonPressed('repeat')" style="margin: 11%;"/>
    <q-btn :disabled="notMapped('left')" color="blue-grey" size="3vh" icon="arrow_left" class="number" v-on:click="buttonPressed('left')" />
    <q-btn :disabled="notMapped('ok')" color="black" size="2vh" icon="my_location" class="number" v-on:click="buttonPressed('ok')" />
    <q-btn :disabled="notMapped('right')" color="blue-grey" size="3vh" icon="arrow_right" class="number" v-on:click="buttonPressed('right')" />
    <q-btn :disabled="notMapped('keyboard')" round color="dark" size="2vh" icon="keyboard" v-on:click="buttonPressed('keyboard')" style="margin: 11%;"/>
    <q-btn :disabled="notMapped('down')" color="blue-grey" size="3vh" icon="arrow_drop_down" class="number" v-on:click="buttonPressed('down')" />
    <q-btn :disabled="notMapped('mouse')" round color="dark" size="2vh" icon="mouse" v-on:click="buttonPressed('mouse')" style="margin: 11%;"/>

    <q-btn :disabled="notMapped('n1')" color="dark" size="2vh" label="1" class="number" v-on:click="buttonPressed('n1')" />
    <q-btn :disabled="notMapped('n2')" color="dark" size="2vh" label="2" class="number" v-on:click="buttonPressed('n2')" />
    <q-btn :disabled="notMapped('n3')" color="dark" size="2vh" label="3" class="number" v-on:click="buttonPressed('n3')" />
    <q-btn :disabled="notMapped('n4')" color="dark" size="2vh" label="4" class="number" v-on:click="buttonPressed('n4')" />
    <q-btn :disabled="notMapped('n5')" color="dark" size="2vh" label="5" class="number" v-on:click="buttonPressed('n5')" />
    <q-btn :disabled="notMapped('n6')" color="dark" size="2vh" label="6" class="number" v-on:click="buttonPressed('n6')" />
    <q-btn :disabled="notMapped('n7')" color="dark" size="2vh" label="7" class="number" v-on:click="buttonPressed('n7')" />
    <q-btn :disabled="notMapped('n8')" color="dark" size="2vh" label="8" class="number" v-on:click="buttonPressed('n8')" />
    <q-btn :disabled="notMapped('n9')" color="dark" size="2vh" label="9" class="number" v-on:click="buttonPressed('n9')" />
    <q-btn :disabled="notMapped('mute')" color="dark" size="2vh" label="mute" class="number" v-on:click="buttonPressed('mute')" />
    <q-btn :disabled="notMapped('n0')" color="dark" size="2vh" label="0" class="number" v-on:click="buttonPressed('n0')" />
    <q-btn :disabled="notMapped('close')" color="dark" size="2vh" label="close" class="number" v-on:click="buttonPressed('close')" />
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
      this.$root.$on('speechResult', (command) => {
        if (command === 'error') {
          this.opened = false
          return
        }
        this.speechResultCommand(command)
      })
    },
    getControlsConfig: function () {
      this.$axios.get('https://' + location.hostname + ':3000/cfg/control/receptor-tv', {control: 'receptor-tv'})
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
      this.$axios.get('https://' + location.hostname + ':3000/calibrar-voz/receptor-tv/' + this.key + '/' + command, {})
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
