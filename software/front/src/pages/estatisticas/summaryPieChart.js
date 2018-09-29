import { Pie } from './baseCharts'

export default {
  extends: Pie,
  props: ['idata'],
  mounted () {
  },
  watch: {
    idata: function (newv) {
      let lbs = newv.map((v) => { return v._id })
      let dat = newv.map((v) => { return v.count })
      this.renderChart({
        labels: lbs,
        datasets: [
          {
            backgroundColor: [
              '#41B883',
              '#E46651',
              '#00D8FF',
              '#DD1B16'
            ],
            data: dat
          }
        ]
      }, {responsive: true, maintainAspectRatio: false})
    }
  }
}
