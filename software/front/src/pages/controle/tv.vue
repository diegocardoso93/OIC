<template>
  <q-page padding id="tv">
      <q-btn color="negative" size="3vh" icon="power_settings_new" v-on:click="buttonPressed(power)" />
      <q-btn color="blue-grey" size="3vh" icon="arrow_drop_down" />
      <q-btn color="blue-grey" size="3vh" icon="arrow_left" />
      <q-btn color="blue-grey" size="3vh" icon="arrow_right" />
      <q-btn color="blue-grey" size="3vh" icon="arrow_drop_up" />

      <q-btn color="black" size="3vh" icon="my_location" />
      <q-btn color="blue-grey" size="3vh" icon="arrow_drop_down" />
      <q-btn color="blue-grey" size="3vh" label="Vol" icon-right="arrow_drop_up" />
      <q-btn color="blue-grey" size="3vh" label="Vol" icon-right="arrow_drop_down" />
      <q-btn color="blue-grey" size="3vh" label="Ch" icon-right="add" />
      <q-btn color="blue-grey" size="3vh" label="Ch" icon-right="remove" />

      <q-btn color="dark" size="3vh" label="1" v-on:click="buttonPressed(1)" />
      <q-btn color="dark" size="3vh" label="2" v-on:click="buttonPressed(2)" />
      <q-btn color="dark" size="3vh" label="3" v-on:click="buttonPressed(3)" />
      <q-btn color="dark" size="3vh" label="4" v-on:click="buttonPressed(4)" />
      <q-btn color="dark" size="3vh" label="5" v-on:click="buttonPressed(5)" />
      <q-btn color="dark" size="3vh" label="6" v-on:click="buttonPressed(6)" />
      <q-btn color="dark" size="3vh" label="7" v-on:click="buttonPressed(7)" />
      <q-btn color="dark" size="3vh" label="8" v-on:click="buttonPressed(8)" />
      <q-btn color="dark" size="3vh" label="9" v-on:click="buttonPressed(9)" />

      <q-btn color="black" size="3vh" icon="audiotrack" />
      <q-btn color="black" size="3vh" icon="child_care" />
  </q-page>
</template>

<script>
export default {
  data () {
    return {
      power: 'power',
      1: '1',
      2: '2',
      3: '3',
      4: '4',
      5: '5',
      6: '6',
      7: '7',
      8: '8',
      9: '9'
    }
  },
  methods: {
    buttonPressed: function (key) {
      this.$axios.get('http://' + location.hostname + ':3000/tv/' + key, {button: key})
        .then((response) => {
          console.log(response)
        })
        .catch(() => {
          alert('error')
        })
    }
  }
}
</script>

<style lang="stylus">
#view-colors
  div.main-color
    width 110px
    margin 5px
    height 40px
  .detailed-color
    width 100%
  div.detailed-color
    height 55px
  div.detail
    margin-bottom 25px
    max-width 400px
    min-width 135px
    display inline-block
    margin-right 5px
  h5
    margin-bottom 5px
    padding 10px 5px
</style>
