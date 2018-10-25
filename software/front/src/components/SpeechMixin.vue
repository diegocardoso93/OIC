<script>
export default {
  data () {
    return {
      voiceActive: false,
      recognition: null,
      speechResult: null
    }
  },
  methods: {
    speechStart () {
      this.voiceActive = true
      this.recognition.start()
    },
    speechInit () {
      let SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition
      // let SpeechGrammarList = window.SpeechGrammarList || window.webkitSpeechGrammarList

      // let oicCommands = Object.keys(voicecommands)
      // let grammar = '#JSGF V1.0; grammar oicCommands; public <oicCommands> = ' + oicCommands.join(' | ') + ' ;'

      this.recognition = new SpeechRecognition()
      // let speechRecognitionList = new SpeechGrammarList()
      // speechRecognitionList.addFromString(grammar, 1)
      // this.recognition.grammars = speechRecognitionList
      // this.recognition.continuous = false
      this.recognition.lang = 'pt-BR'
      this.recognition.interimResults = false
      this.recognition.maxAlternatives = 1

      this.recognition.onresult = (event) => {
        var last = event.results.length - 1
        var command = event.results[last][0].transcript

        console.log('Result received: ' + command)
        console.log('Confidence: ' + event.results[0][0].confidence)
        this.$root.$emit('speechResult', command)
      }

      this.recognition.onspeechend = () => {
        this.recognition.stop()
        this.voiceActive = false
        this.$root.$emit('speechResult', 'error')
      }

      this.recognition.onnomatch = (event) => {
        console.log('didnt recognise that command')
        this.voiceActive = false
        this.$root.$emit('speechResult', 'error')
      }

      this.recognition.onerror = (event) => {
        console.log('Error occurred in recognition: ' + event.error)
        this.voiceActive = false
        this.$root.$emit('speechResult', 'error')
      }
    }
  },
  created: function () {
    this.speechInit()
  }
}
</script>
