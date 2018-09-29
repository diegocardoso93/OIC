<template>
  <q-page id="tv">
    <q-btn round color="negative" size="2vh" icon="power_settings_new" class="power" v-on:click="buttonPressed('power')" />
    <q-btn round color="dark" size="2vh" icon="power_settings_new" class="power" style="float: right" v-on:click="buttonPressed('power_tv')" />
    <br/>

    <button tabindex="0" type="button" v-on:click="buttonPressed('set_tv')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">SET</div>
    </button>
    <button tabindex="0" type="button" v-on:click="buttonPressed('tv_in')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">TV IN</div>
    </button>
    <button tabindex="0" type="button" v-on:click="buttonPressed('vol-_tv')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">VOL-</div>
    </button>
    <button tabindex="0" type="button" v-on:click="buttonPressed('vol+_tv')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">VOL+</div>
    </button>

    <button tabindex="0" type="button" v-on:click="buttonPressed('setup')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-red text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">SETUP</div>
    </button>
    <button tabindex="0" type="button" v-on:click="buttonPressed('app')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-green text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">APP</div>
    </button>
    <button tabindex="0" type="button" v-on:click="buttonPressed('vol-')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-yellow text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">VOL-</div>
    </button>
    <button tabindex="0" type="button" v-on:click="buttonPressed('vol+')" class="q-btn inline relative-position q-btn-item non-selectable small-1 q-btn-rectangle q-focusable q-hoverable bg-blue text-white" style="font-size: 2vh;">
      <div class="q-btn-inner row col items-center justify-center">VOL+</div>
    </button>

    <q-btn round color="dark" size="2vh" icon="home" v-on:click="buttonPressed('home')" style="margin: 11%;"/>
    <q-btn color="blue-grey" size="3vh" icon="arrow_drop_up" class="number" v-on:click="buttonPressed('up')" />
    <q-btn round color="dark" size="2vh" icon="repeat" v-on:click="buttonPressed('repeat')" style="margin: 11%;"/>
    <q-btn color="blue-grey" size="3vh" icon="arrow_left" class="number" v-on:click="buttonPressed('left')" />
    <q-btn color="black" size="2vh" icon="my_location" class="number" v-on:click="buttonPressed('ok')" />
    <q-btn color="blue-grey" size="3vh" icon="arrow_right" class="number" v-on:click="buttonPressed('right')" />
    <q-btn round color="dark" size="2vh" icon="keyboard" v-on:click="buttonPressed('keyboard')" style="margin: 11%;"/>
    <q-btn color="blue-grey" size="3vh" icon="arrow_drop_down" class="number" v-on:click="buttonPressed('down')" />
    <q-btn round color="dark" size="2vh" icon="mouse" v-on:click="buttonPressed('mouse')" style="margin: 11%;"/>

    <q-btn color="dark" size="2vh" label="1" class="number" v-on:click="buttonPressed('1')" />
    <q-btn color="dark" size="2vh" label="2" class="number" v-on:click="buttonPressed('2')" />
    <q-btn color="dark" size="2vh" label="3" class="number" v-on:click="buttonPressed('3')" />
    <q-btn color="dark" size="2vh" label="4" class="number" v-on:click="buttonPressed('4')" />
    <q-btn color="dark" size="2vh" label="5" class="number" v-on:click="buttonPressed('5')" />
    <q-btn color="dark" size="2vh" label="6" class="number" v-on:click="buttonPressed('6')" />
    <q-btn color="dark" size="2vh" label="7" class="number" v-on:click="buttonPressed('7')" />
    <q-btn color="dark" size="2vh" label="8" class="number" v-on:click="buttonPressed('8')" />
    <q-btn color="dark" size="2vh" label="9" class="number" v-on:click="buttonPressed('9')" />
    <q-btn color="dark" size="2vh" label="mute" class="number" v-on:click="buttonPressed('mute')" />
    <q-btn color="dark" size="2vh" label="0" class="number" v-on:click="buttonPressed('0')" />
    <q-btn color="dark" size="2vh" label="close" class="number" v-on:click="buttonPressed('close')" />
  </q-page>
</template>

<script>
export default {
  data () {
    return {
      btn: {}
    }
  },
  methods: {
    buttonPressed: function (key) {
      this.$axios.get('http://' + location.hostname + ':3000/receptor-tv/' + key, {button: key})
        .then((response) => {
          console.log(response)
        })
        .catch((e) => {
          console.log('error', e)
        })
    },
    getControlsConfig: function () {
      this.$axios.get('http://' + location.hostname + ':3000/cfg/control/receptor-tv', {control: 'receptor-tv'})
        .then((response) => {
          this.btn = response.data.control.button
        })
        .catch((e) => {
          console.log('error', e)
        })
    },
    notMapped: function (btnLabel) {
      return !(this.btn[btnLabel] && this.btn[btnLabel].length > 0)
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
