<template>
  <q-page padding id="iluminacao">
    <div class="overlay">
      <button :disabled="notMapped('brighthness_70')" tabindex="0" type="button" v-on:click="buttonPressed('brighthness_70')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-white text-dark button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">
          <i aria-hidden="true" class="q-icon material-icons">brightness_5</i>
        </div>
      </button>
      <button :disabled="notMapped('brighthness_50')" tabindex="0" type="button" v-on:click="buttonPressed('brighthness_50')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-white text-dark button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">
          <i aria-hidden="true" class="q-icon material-icons">brightness_2</i>
        </div>
      </button>
      <button :disabled="notMapped('brighthness_0')" tabindex="0" type="button" v-on:click="buttonPressed('brighthness_0')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-black text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">
          <i aria-hidden="true" class="q-icon material-icons">lightbulb_outline</i>
        </div>
      </button>
      <button :disabled="notMapped('brighthness_100')" tabindex="0" type="button" v-on:click="buttonPressed('brighthness_100')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-red text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">
          <i aria-hidden="true" class="q-icon material-icons">wb_incandescent</i>
        </div>
      </button>
      <br/>
      <button :disabled="notMapped('r')" tabindex="0" type="button" v-on:click="buttonPressed('r')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-red text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">r</div>
      </button>
      <button :disabled="notMapped('g')" tabindex="0" type="button" v-on:click="buttonPressed('g')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-green text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">g</div>
      </button>
      <button :disabled="notMapped('b')" tabindex="0" type="button" v-on:click="buttonPressed('b')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-blue text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">b</div>
      </button>
      <button :disabled="notMapped('w')" tabindex="0" type="button" v-on:click="buttonPressed('w')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-white text-black button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">w</div>
      </button>
      <br/>
      <q-btn :disabled="notMapped('c1')" round size="3vh" v-on:click="buttonPressed('c1')" class="button-md-3" style="background-color: rgba(255,83,25)" />
      <q-btn :disabled="notMapped('c2')" round size="3vh" v-on:click="buttonPressed('c2')" class="button-md-3" style="background-color: rgba(60,212,95)" />
      <q-btn :disabled="notMapped('c3')" round size="3vh" v-on:click="buttonPressed('c3')" class="button-md-3" style="background-color: rgba(108,108,212)" />
      <button :disabled="notMapped('flash')" tabindex="0" type="button" v-on:click="buttonPressed('flash')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-dark text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center button-text">flash</div>
      </button>
      <br/>
      <q-btn :disabled="notMapped('c4')" round size="3vh" v-on:click="buttonPressed('c4')" class="button-md-3" style="background-color: rgba(255,106,94)" />
      <q-btn :disabled="notMapped('c5')" round size="3vh" v-on:click="buttonPressed('c5')" class="button-md-3" style="background-color: rgba(71,227,198)" />
      <q-btn :disabled="notMapped('c6')" round size="3vh" v-on:click="buttonPressed('c6')" class="button-md-3" style="background-color: rgba(93,42,227)" />
      <button :disabled="notMapped('strobe')" tabindex="0" type="button" v-on:click="buttonPressed('strobe')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-dark text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center button-text">strobe</div>
      </button>
      <br/>
      <q-btn :disabled="notMapped('c7')" round size="3vh" v-on:click="buttonPressed('c7')" class="button-md-3" style="background-color: rgba(255,146,107)" />
      <q-btn :disabled="notMapped('c8')" round size="3vh" v-on:click="buttonPressed('c8')" class="button-md-3" style="background-color: rgba(68,197,222)" />
      <q-btn :disabled="notMapped('c9')" round size="3vh" v-on:click="buttonPressed('c9')" class="button-md-3" style="background-color: rgba(144,37,222)" />
      <button :disabled="notMapped('fade')" tabindex="0" type="button" v-on:click="buttonPressed('fade')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-dark text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center button-text">fade</div>
      </button>
      <br/>
      <q-btn :disabled="notMapped('c10')" round size="3vh" v-on:click="buttonPressed('c10')" class="button-md-3" style="background-color: rgba(243,246,47)" />
      <q-btn :disabled="notMapped('c11')" round size="3vh" v-on:click="buttonPressed('c11')" class="button-md-3" style="background-color: rgba(40,154,227)" />
      <q-btn :disabled="notMapped('c12')" round size="3vh" v-on:click="buttonPressed('c12')" class="button-md-3" style="background-color: rgba(190,17,227)" />
      <button :disabled="notMapped('smooth')" tabindex="0" type="button" v-on:click="buttonPressed('smooth')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-dark text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center button-text">smooth</div>
      </button>
    </div>
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
      this.$axios.get('https://' + location.hostname + ':3000/light/' + key, {button: key})
        .then((response) => {
          console.log(response)
        })
        .catch((e) => {
          console.log('error', e)
        })
    },
    getControlsConfig: function () {
      this.$axios.get('https://' + location.hostname + ':3000/cfg/control/light', {control: 'light'})
        .then((response) => {
          console.log(response)
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
.overlay
  background-color rgba(200, 200, 200, 0.5)
  border-radius 10px
  text-align center

.button-text
  font-size 12px

.button-md-3
  margin 2.4% 2.6%
  max-width 19.4%
</style>
