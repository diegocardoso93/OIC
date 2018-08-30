<template>
  <q-layout view="lHh Lpr lFf main-color shadow-1 row inline flex-center text-white bg-black">
    <q-layout-header>
      <q-toolbar
        color="primary"
        :glossy="$q.theme === 'mat'"
        :inverted="$q.theme === 'ios'"
      >
        <q-btn
          dense
          round
          v-go-back=" '/' "
          color="primary"
          label="voltar"
        >
          <q-icon name="arrow_back" />
        </q-btn>

        <q-toolbar-title>
          OIC
          <div slot="subtitle">Controle</div>
        </q-toolbar-title>
      </q-toolbar>
    </q-layout-header>

    <q-page-container class="back-black">
      <router-view />
    </q-page-container>
  </q-layout>
</template>

<script>
import { openURL } from 'quasar'

export default {
  name: 'MyLayout',
  data () {
    return {
      leftDrawerOpen: this.$q.platform.is.desktop
    }
  },
  methods: {
    openURL
  }
}
</script>

<style lang="stylus">
.back-black
  background-color: #000
</style>
