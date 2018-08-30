<template>
  <q-layout view="lHh Lpr lFf">
    <q-layout-header>
      <q-toolbar
        color="primary"
      >
        <q-btn
          flat
          dense
          round
          @click="drawerState = !drawerState"
          aria-label="Menu"
        >
          <q-icon name="menu" />
        </q-btn>

        <q-toolbar-title>
          <q-icon
            v-show="pageMeta.icon"
            style="font-size: 2rem; margin-right: 5px;"
            :name="pageMeta.icon"
          />
          {{ pageMeta.title }}
          <div slot="subtitle">{{ pageMeta.subtitle }}</div>
        </q-toolbar-title>
      </q-toolbar>
    </q-layout-header>

    <q-layout-drawer
      v-model="drawerState"
      :content-class="$q.theme === 'mat' ? 'bg-grey-2' : null"
    >
      <div class="row flex-center bg-white" style="height: 115px">
        <img alt="BigHealth logo" src="~assets/logo.jpg" style="height: 75px; width 75px;">
        <div class="caption q-ml-md">
          BigHealth v0.0.1
        </div>
      </div>
      <q-list
        no-border
        link
        inset-delimiter
      >
        <q-item
          to="/"
          exact
          replace
        >
          <q-item-side icon="home" />
          <q-item-main label="Principal" />
        </q-item>
        <template v-for="category in categories">
          <q-list-header :key="`header-${category.title}`">
            {{ category.title }}
          </q-list-header>
          <q-item
            v-for="feature in category.features"
            :key="category.hash+feature.hash"
            :to="`/healthcase/${category.hash}/${feature.hash}`"
            :replace="!category.extract"
          >
            <q-item-side :icon="feature.icon" />
            <q-item-main :label="feature.title" />
          </q-item>
        </template>
        <q-item-separator />
        <q-list-header>Links Importantes</q-list-header>
        <q-item @click.native="openURL('http://quasar-framework.org')">
          <q-item-side icon="school" />
          <q-item-main label="Docs Quasar" sublabel="quasar-framework.org" />
        </q-item>
        <q-item @click.native="openURL('https://docs.bigchaindb.com/en/latest/index.html')">
          <q-item-side icon="view_array" />
          <q-item-main label="Docs BigChainDB" sublabel="docs.bigchaindb.com" />
        </q-item>
        <q-item @click.native="openURL('https://blog.bigchaindb.com/using-mongodb-to-query-bigchaindb-data-3fc651e0861b')">
          <q-item-side icon="account circle" />
          <q-item-main label="Car example" sublabel="Using MongoDB to Query BigchainDB Data" />
          <q-item-side right icon="thumb_up" />
        </q-item>
      </q-list>
    </q-layout-drawer>

    <q-page-container>
      <transition
        enter-active-class="animated fadeIn"
        leave-active-class="animated fadeOut"
        mode="out-in"
        :duration="300"
        @leave="resetScroll"
      >
        <router-view />
      </transition>
    </q-page-container>
  </q-layout>
</template>

<script>
import { openURL } from 'quasar'
import { mapState } from 'vuex'
import categories from 'assets/categories'

export default {
  name: 'LayoutDefault',
  data () {
    return {
      categories
    }
  },
  computed: {
    drawerState: {
      get () {
        return this.$store.state.healthcase.drawerState
      },
      set (val) {
        this.$store.commit('healthcase/updateDrawerState', val)
      }
    },
    ...mapState('healthcase', [
      'pageMeta'
    ])
  },
  methods: {
    openURL,
    resetScroll (el, done) {
      document.documentElement.scrollTop = 0
      document.body.scrollTop = 0
      done()
    }
  },
  mounted () {
    if (this.$q.platform.is.desktop && !this.drawerState) {
      this.drawerState = true
    }
  }
}
</script>

<style>
</style>
