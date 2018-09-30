<template>
  <q-page id="estatisticas">
    <div class="layout-view">
      <div class="q-title" v-show="summaryData">controles mais utilizados</div>
      <summary-pie-chart class="pie" :idata="summaryData" v-show="summaryData"></summary-pie-chart>
      <div class="q-title" v-text="cData[0] ? cData[0]['label'] : ''"></div>
      <horizontal-bar :idata="cData[0]" v-show="cData[0]"></horizontal-bar>
      <div class="q-title" v-text="cData[1] ? cData[1]['label'] : ''"></div>
      <horizontal-bar :idata="cData[1]" v-show="cData[1]"></horizontal-bar>
      <div class="q-title" v-text="cData[2] ? cData[2]['label'] : ''"></div>
      <horizontal-bar :idata="cData[2]" v-show="cData[2]"></horizontal-bar>
    </div>
  </q-page>
</template>

<script>
import SummaryPieChart from './summaryPieChart'
import HorizontalBar from './horizontalBar'

export default {
  components: {
    SummaryPieChart,
    HorizontalBar
  },
  data () {
    return {
      summaryData: null,
      cData: []
    }
  },
  mounted () {
    this.$axios.get('http://' + location.hostname + ':3000/stats/control-use')
      .then((response) => {
        console.log(response)
        this.summaryData = response.data.graph
      })
      .catch((e) => {
        console.log('error', e)
      })
    this.$axios.get('http://' + location.hostname + ':3000/stats/control-button')
      .then((response) => {
        console.log(response)
        let x = response.data.graph
        x.forEach((val) => {
          let buttons = []
          let values = []
          val['buttons'].forEach((btn) => {
            buttons.push(btn.button)
            values.push(btn.count)
          })
          this.cData.push({
            label: val['_id']['control'],
            buttons: buttons,
            values: values
          })
        })
      })
      .catch((e) => {
        console.log('error', e)
      })
  }
}
</script>

<style lang="stylus">
#estatisticas
  background-color #fff
#pie-chart
  height 250px !important
  margin auto
.q-title
  padding 16px 0px 0px 0px
  text-align center
</style>
