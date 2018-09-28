<template>
  <q-page id="tv">
    <p class="info-text">Clique sobre o botão e aponte o controle remoto real para a Central, pressione e aguarde fechar a mensagem, ao final o botão estará calibrado. Repita o processo para cada um dos botões.</p>
    <q-btn round color="negative" size="2vh" icon="power_settings_new" class="power" v-on:click="buttonPressed('power')" />
    <button tabindex="0" type="button" v-on:click="buttonPressed('tv')" class="q-btn inline relative-position q-btn-item non-selectable power q-btn-round q-focusable q-hoverable bg-dark text-white" style="font-size: 2vh;float: right">
      <div class="q-btn-inner row col items-center justify-center">TV</div>
    </button>
    <br/>
    <q-btn color="dark" size="2vh" class="small-1" label="caption" v-on:click="buttonPressed('caption')" />
    <q-btn color="dark" size="2vh" class="small-1" icon="help" v-on:click="buttonPressed('help')" />
    <q-btn color="dark" size="2vh" class="small-1" icon="search" v-on:click="buttonPressed('search')" />
    <q-btn color="dark" size="2vh" class="small-1" icon="home" v-on:click="buttonPressed('home')" />

    <q-btn color="dark" size="3vh" label="1" class="number" v-on:click="buttonPressed('n1')" />
    <q-btn color="dark" size="3vh" label="2" class="number" v-on:click="buttonPressed('n2')" />
    <q-btn color="dark" size="3vh" label="3" class="number" v-on:click="buttonPressed('n3')" />
    <q-btn color="dark" size="3vh" label="4" class="number" v-on:click="buttonPressed('n4')" />
    <q-btn color="dark" size="3vh" label="5" class="number" v-on:click="buttonPressed('n5')" />
    <q-btn color="dark" size="3vh" label="6" class="number" v-on:click="buttonPressed('n6')" />
    <q-btn color="dark" size="3vh" label="7" class="number" v-on:click="buttonPressed('n7')" />
    <q-btn color="dark" size="3vh" label="8" class="number" v-on:click="buttonPressed('n8')" />
    <q-btn color="dark" size="3vh" label="9" class="number" v-on:click="buttonPressed('n9')" />
    <q-btn color="dark" size="2vh" label="list" class="number" v-on:click="buttonPressed('list')" />
    <q-btn color="dark" size="3vh" label="0" class="number" v-on:click="buttonPressed('n0')" />
    <q-btn color="dark" size="2vh" label="flashbk" class="number" v-on:click="buttonPressed('flashbk')" />

    <div style="width:33%;float:left">
      <q-btn color="blue-grey" size="3vh" label="Vol" icon-right="add" class="lg-in" v-on:click="buttonPressed('volp')" />
      <q-btn color="blue-grey" size="3vh" label="Ch" icon-right="add" class="lg-in" v-on:click="buttonPressed('chp')" />
    </div>
    <div style="width:33%;float:left">
      <q-btn color="dark" size="2vh" label="fav" class="sm-in" v-on:click="buttonPressed('fav')" />
      <q-btn color="dark" size="2vh" label="info" class="sm-in" v-on:click="buttonPressed('info')" />
      <q-btn color="dark" size="2vh" label="mute" class="sm-in" v-on:click="buttonPressed('mute')" />
    </div>
    <div style="width:33%;float:left">
      <q-btn color="blue-grey" size="3vh" label="Vol" icon-right="remove" class="lg-in" v-on:click="buttonPressed('volm')" />
      <q-btn color="blue-grey" size="3vh" label="Ch" icon-right="remove" class="lg-in" v-on:click="buttonPressed('chm')"/>
    </div>

    <q-btn color="blue-grey" size="2vh" icon="settings" class="number" v-on:click="buttonPressed('settings')" />
    <q-btn color="blue-grey" size="3vh" icon="arrow_drop_up" class="number" v-on:click="buttonPressed('up')" />
    <q-btn color="blue-grey" size="2vh" label="livezoom" class="number" v-on:click="buttonPressed('livezoom')" />
    <q-btn color="blue-grey" size="3vh" icon="arrow_left" class="number" v-on:click="buttonPressed('left')" />
    <q-btn color="black" size="3vh" icon="my_location" class="number" v-on:click="buttonPressed('ok')" />
    <q-btn color="blue-grey" size="3vh" icon="arrow_right" class="number" v-on:click="buttonPressed('right')" />
    <q-btn color="blue-grey" size="2vh" label="back" class="number" v-on:click="buttonPressed('back')" />
    <q-btn color="blue-grey" size="3vh" icon="arrow_drop_down" class="number" v-on:click="buttonPressed('down')" />
    <q-btn color="blue-grey" size="2vh" label="exit" class="number" v-on:click="buttonPressed('exit')" />

    <q-btn color="blue-grey" size="2vh" label="sap/*" class="number" v-on:click="buttonPressed('sap')" />
    <q-btn color="blue-grey" size="2vh" label="sleep" class="number" v-on:click="buttonPressed('sleep')" />
    <q-btn color="blue-grey" size="2vh" icon="stop" class="number" v-on:click="buttonPressed('stop')" />

    <q-btn color="dark" size="2vh" class="small-1" icon="fast_rewind" v-on:click="buttonPressed('rewind')" />
    <q-btn color="dark" size="2vh" class="small-1" icon="play_arrow" v-on:click="buttonPressed('play')" />
    <q-btn color="dark" size="2vh" class="small-1" icon="pause" v-on:click="buttonPressed('pause')" />
    <q-btn color="dark" size="2vh" class="small-1" icon="fast_forward" v-on:click="buttonPressed('forward')" />

    <q-btn color="red" size="2vh" class="small-1" icon="fiber_manual_record" v-on:click="buttonPressed('point1')" />
    <q-btn color="green" size="2vh" class="small-1" icon="fiber_manual_record" v-on:click="buttonPressed('point2')" />
    <q-btn color="yellow" size="2vh" class="small-1" icon="fiber_manual_record" v-on:click="buttonPressed('point3')" />
    <q-btn color="blue" size="2vh" class="small-1" icon="fiber_manual_record" v-on:click="buttonPressed('point4')" />

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
      btnCalibrando: '',
      opened: false
    }
  },
  methods: {
    buttonPressed: function (key) {
      this.$axios.get('http://' + location.hostname + ':3000/calibrate/tv/' + key)
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

.info-text
  color white
  text-align justify
</style>
