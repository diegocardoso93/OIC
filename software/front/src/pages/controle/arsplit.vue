<template>
  <q-page padding id="tv">
      <q-btn color="negative" size="3vh" icon="power_settings_new" />
      <q-btn color="blue-grey" size="3vh" icon="exposure_plus_1" />
      <q-btn color="blue-grey" size="3vh" icon="exposure_plus_2" />
      <q-btn color="blue-grey" size="3vh" icon="exposure_neg_1" />
      <q-btn color="blue-grey" size="3vh" icon="exposure_neg_2" />
  </q-page>
</template>

<script>
export default {
  data () {
    return {
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
