<template>
  <q-page id="estatisticas">
   <div class="q-title">controles mais utilizados</div>
   <div class="layout-view">
      <summary-pie-chart class="pie" :idata="summaryData"></summary-pie-chart>
    </div>
  </q-page>
</template>

<script>
import SummaryPieChart from './summaryPieChart'

export default {
  components: {
    SummaryPieChart
  },
  data () {
    return {
      summaryData: {}
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
