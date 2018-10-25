<template>
  <q-page padding class="page-home">
    <div class="home-top text-center">
      <img src="~assets/logo.jpg">

      <p class="caption">
        Seja bem-vindo.
      </p>
    </div>

    <div class="row justify-center">
      <div style="width: 850px; max-width: 90vw;" class="row">
        <div
          v-for="category in list"
          :key="category.hash"
          class="col-xs-6 col-sm-4 col-lg-3"
        >
          <div class="card text-center category-link text-primary" @click="show(category)"
            :class="(category.hash === 'speech' && voiceActive) ? 'hoveron' : ''">
            <q-icon :name="category.icon" />
            <p class="caption">{{ category.title }}</p>
          </div>
        </div>
      </div>
    </div>

    <q-page-sticky v-show="category" position="bottom-right" :offset="[18, 18]">
      <q-btn round color="secondary" @click="category = false" class="animate-pop">
        <q-icon name="keyboard_backspace" />
      </q-btn>
    </q-page-sticky>
  </q-page>
</template>

<script>
import categories from '../assets/categories'
import SpeechMixin from '../components/SpeechMixin'
import voicecommands from '../assets/voicecommands'

export default {
  data () {
    return {
      category: false,
      voiceActive: false
    }
  },
  mixins: [SpeechMixin],
  computed: {
    list () {
      return this.category || categories
    }
  },
  methods: {
    show (link) {
      if (link.features && link.features.length) {
        this.category = link.features
        this.hash = link.hash
        return
      }
      if (link.hash === 'speech') {
        this.speechStart()
      } else if (this.hash) {
        this.$router.push(`/home/${this.hash}/${link.hash}`)
      } else {
        this.$router.push(`/home/${link.hash}`)
      }
    },
    speechResult: function (command) {
      command = command.toLowerCase()
      if (voicecommands[command]) {
        this.sendCommand(voicecommands[command])
      }
    },
    sendCommand: function (commands) {
      let count = 0
      commands.forEach((val, key) => {
        if (key === 0) return
        setTimeout(() => {
          this.$axios.get('https://' + location.hostname + ':3000/' + commands[0] + '/' + val, {button: val})
            .then((response) => {
              console.log(response)
            })
            .catch((e) => {
              console.log('error', e)
            })
        }, 300 * ++count)
      })
    }
  }
}
</script>

<style lang="stylus">
@import '~variables'
.page-home
  img
    width 100px
    height 100px
    margin-bottom 15px
  .home-top
    margin-bottom 15px
    .q-alert
      max-width 500px
  .card
    cursor pointer
    position relative
    padding 16px
    .q-icon
      font-size 56px
    p
      color rgba(0, 0, 0, .87)
      margin 15px 0 0 0 !important
    &:before
      content ''
      position absolute
      top 0
      right 0
      bottom 0
      left 0
      border-radius 2px
      opacity 0
      transition opacity .2s
      background currentColor
  .hoveron:before
      opacity .4
</style>
