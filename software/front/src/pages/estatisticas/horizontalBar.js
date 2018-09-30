import { HorizontalBar } from './baseCharts'

export default {
  extends: HorizontalBar,
  props: ['idata'],
  mounted () {
  },
  watch: {
    idata: function (newv) {
      this.renderChart({
        labels: newv.buttons,
        datasets: [
          {
            label: newv.label,
            backgroundColor: '#f87979',
            data: newv.values
          }
        ]
      },
      {
        responsive: true,
        maintainAspectRatio: false,
        scales: {
          xAxes: [{
            ticks: {
              beginAtZero: true
            },
            barPercentage: 0.1
          }],
          yAxes: [{
            ticks: {
              beginAtZero: true
            },
            barPercentage: 0.1
          }]
        }
      })
    }
  }
}
