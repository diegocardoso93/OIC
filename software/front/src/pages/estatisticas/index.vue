<template>
  <q-page id="estatisticas">
    <div class="layout-view">
      <example-chart :data="data"></example-chart>
    </div>
  </q-page>
</template>

<script>
import exampleChart from './exampleChart'
export default {
  components: {
    exampleChart
  },
  data () {
    return {
      data: {
        labels: ['A', 'B', 'C'],
        datasets: [{
          label: ['One', 'Two', 'Three'],
          backgroundColor: ['#f80', '#800', '#888'],
          data: [10, 20, 30]
        }],
        option: {
          heigth: 200
        }
      }
    }
  },
  methods: {
  },
  mounted: function () {
  }
}
</script>

<style lang="stylus">
#estatisticas
  background-color #fff
</style>
