<template>
  <q-page padding id="iluminacao">
    <div class="overlay">
      <button tabindex="0" type="button" v-on:click="buttonPressed('brighthness_70')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-white text-dark button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">
          <i aria-hidden="true" class="q-icon material-icons">brightness_5</i>
        </div>
      </button>
      <button tabindex="0" type="button" v-on:click="buttonPressed('brighthness_50')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-white text-dark button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">
          <i aria-hidden="true" class="q-icon material-icons">brightness_2</i>
        </div>
      </button>
      <button tabindex="0" type="button" v-on:click="buttonPressed('brighthness_0')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-black text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">
          <i aria-hidden="true" class="q-icon material-icons">lightbulb_outline</i>
        </div>
      </button>
      <button tabindex="0" type="button" v-on:click="buttonPressed('brighthness_100')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-red text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">
          <i aria-hidden="true" class="q-icon material-icons">wb_incandescent</i>
        </div>
      </button>
      <br/>
      <button tabindex="0" type="button" v-on:click="buttonPressed('r')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-red text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">r</div>
      </button>
      <button tabindex="0" type="button" v-on:click="buttonPressed('g')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-green text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">g</div>
      </button>
      <button tabindex="0" type="button" v-on:click="buttonPressed('b')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-blue text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">b</div>
      </button>
      <button tabindex="0" type="button" v-on:click="buttonPressed('w')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-white text-black button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center">w</div>
      </button>
      <br/>
      <q-btn round size="3vh" v-on:click="buttonPressed('c1')" class="button-md-3" style="background-color: rgba(255,83,25)" />
      <q-btn round size="3vh" v-on:click="buttonPressed('c2')" class="button-md-3" style="background-color: rgba(60,212,95)" />
      <q-btn round size="3vh" v-on:click="buttonPressed('c3')" class="button-md-3" style="background-color: rgba(108,108,212)" />
      <button tabindex="0" type="button" v-on:click="buttonPressed('flash')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-dark text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center button-text">flash</div>
      </button>
      <br/>
      <q-btn round size="3vh" v-on:click="buttonPressed('c4')" class="button-md-3" style="background-color: rgba(255,106,94)" />
      <q-btn round size="3vh" v-on:click="buttonPressed('c5')" class="button-md-3" style="background-color: rgba(71,227,198)" />
      <q-btn round size="3vh" v-on:click="buttonPressed('c6')" class="button-md-3" style="background-color: rgba(93,42,227)" />
      <button tabindex="0" type="button" v-on:click="buttonPressed('strobe')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-dark text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center button-text">strobe</div>
      </button>
      <br/>
      <q-btn round size="3vh" v-on:click="buttonPressed('c7')" class="button-md-3" style="background-color: rgba(255,146,107)" />
      <q-btn round size="3vh" v-on:click="buttonPressed('c8')" class="button-md-3" style="background-color: rgba(68,197,222)" />
      <q-btn round size="3vh" v-on:click="buttonPressed('c9')" class="button-md-3" style="background-color: rgba(144,37,222)" />
      <button tabindex="0" type="button" v-on:click="buttonPressed('fade')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-dark text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center button-text">fade</div>
      </button>
      <br/>
      <q-btn round size="3vh" v-on:click="buttonPressed('c10')" class="button-md-3" style="background-color: rgba(243,246,47)" />
      <q-btn round size="3vh" v-on:click="buttonPressed('c11')" class="button-md-3" style="background-color: rgba(40,154,227)" />
      <q-btn round size="3vh" v-on:click="buttonPressed('c12')" class="button-md-3" style="background-color: rgba(190,17,227)" />
      <button tabindex="0" type="button" v-on:click="buttonPressed('smooth')" class="q-btn inline relative-position q-btn-item non-selectable q-btn-round q-focusable q-hoverable bg-dark text-white button-md-3" style="font-size: 3vh;">
        <div class="q-btn-inner row col items-center justify-center button-text">smooth</div>
      </button>
    </div>

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
    }
  },
  methods: {
    buttonPressed: function (key) {
      this.$axios.get('http://' + location.hostname + ':3000/calibrate/iluminacao/' + key)
        .then((response) => {
          console.log(response)
          this.btnCalibrando = key
          this.opened = true
          let timebias = 30000, timecount = 0
          let feedInterval = setInterval(() => {
            if (!this.opened || timecount >= timebias) clearInterval(feedInterval)
            this.$axios.get('http://' + location.hostname + ':3000/feed/calibrate')
              .then((response) => {
                console.log(response)
                if (response.data.active === false) {
                  this.opened = false
                  this.btnCalibrando = ''
                }
              })
            timecount += 1000
          }, 1000)
        })
        .catch((e) => {
          console.log('error', e)
        })
    }
  }
}
</script>

<style lang="stylus">
.overlay
  background-color rgba(200, 200, 200, 0.5)
  border-radius 10px

.button-text
  font-size 12px

.button-md-3
  margin 2% 3.9%
  width 17.2%
</style>
