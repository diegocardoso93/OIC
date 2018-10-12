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
import voicecommands from '../assets/voicecommands'
export default {
  data () {
    return {
      category: false,
      voiceActive: false
    }
  },
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
    speechStart () {
      this.voiceActive = true
      this.recognition.start()
    },
    speechInit () {
      let SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition
      let SpeechGrammarList = window.SpeechGrammarList || window.webkitSpeechGrammarList

      let oicCommands = Object.keys(voicecommands)
      let grammar = '#JSGF V1.0; grammar oicCommands; public <oicCommands> = ' + oicCommands.join(' | ') + ' ;'

      this.recognition = new SpeechRecognition()
      let speechRecognitionList = new SpeechGrammarList()
      speechRecognitionList.addFromString(grammar, 1)
      this.recognition.grammars = speechRecognitionList
      // this.recognition.continuous = false
      this.recognition.lang = 'pt-BR'
      this.recognition.interimResults = false
      this.recognition.maxAlternatives = 1

      this.recognition.onresult = (event) => {
        var last = event.results.length - 1
        var command = event.results[last][0].transcript

        console.log('Result received: ' + command)
        console.log('Confidence: ' + event.results[0][0].confidence)
        command = command.toLowerCase()
        if (voicecommands[command]) {
          this.sendCommand(voicecommands[command])
        }
      }

      this.recognition.onspeechend = () => {
        this.recognition.stop()
        this.voiceActive = false
      }

      this.recognition.onnomatch = (event) => {
        console.log('didnt recognise that command')
        this.voiceActive = false
      }

      this.recognition.onerror = function (event) {
        console.log('Error occurred in recognition: ' + event.error)
        this.voiceActive = false
      }
    },
    sendCommand: function (commands) {
      commands.forEach((val, key) => {
        if (key === 0) return
        this.$axios.get('https://' + location.hostname + ':3000/' + commands[0] + '/' + val,
          { button: val, httpsAgent: new https.Agent({ rejectUnauthorized: false }) })
          .then((response) => {
            console.log(response)
          })
          .catch((e) => {
            console.log('error', e)
          })
      })
    }
  },
  mounted () {
    this.speechInit()
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
