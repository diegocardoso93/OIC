<template>
  <q-page id="estatisticas">
    <div class="layout-view">
      <summary-pie-chart></summary-pie-chart>
    </div>
  </q-page>
</template>

<script>
import SummaryPieChart from './summaryPieChart'

export default {
  components: {
    SummaryPieChart
  },
  mounted () {
    this.$axios.get('http://' + location.hostname + ':3000/stats/control-use')
      .then((response) => {
        console.log(response)
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
</style>
