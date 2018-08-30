<template>
  <q-page padding id="tv">
      <q-btn round color="dark" icon="brightness_1" />
      <q-btn round color="dark" icon="brightness_2" />
      <q-btn round color="dark" icon="brightness_3" />
      <q-btn round color="dark" icon="brightness_4" />
      <q-btn round color="dark" icon="brightness_5" />
      <q-btn round color="dark" icon="brightness_6" />
      <q-btn round color="dark" icon="brightness_7" />
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
