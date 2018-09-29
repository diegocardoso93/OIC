import categories from 'assets/categories'

const routes = [
]

function lazyLoad (path, meta) {
  console.log(path, meta)
  return {
    path,
    meta,
    component: () => import('pages/' + path)
  }
}

const oicRouter = {
  path: '/home',
  component: () => import('layouts/MyLayout'),
  children: [
    {
      path: '',
      meta: {
        title: 'OIC',
        hash: '/home',
        icon: 'home',
        backRoute: '/'
      },
      component: () => import('pages/Index')
    }
  ]
}

const oicControle = {
  path: '/home',
  component: () => import('layouts/Controle'),
  children: []
}

const oicCalibrar = {
  path: '/home',
  component: () => import('layouts/Calibrar'),
  children: []
}

const oicEstatisticas = {
  path: '/home',
  component: () => import('layouts/Estatisticas'),
  children: [{
    path: 'estatisticas',
    meta: {},
    component: () => import('pages/estatisticas/index')
  }]
}

categories.forEach(category => {
  if (category.extract) {
    return
  }
  category.features.forEach(feature => {
    if (!feature.tabs) {
      oicControle.children.push(lazyLoad('controle/' + feature.hash, feature))
      oicCalibrar.children.push(lazyLoad('calibrar/' + feature.hash, feature))
    }
  })
})

// Always leave this as last one
if (process.env.MODE !== 'ssr') {
  routes.push(oicRouter)
  routes.push(oicControle)
  routes.push(oicCalibrar)
  routes.push(oicEstatisticas)
  routes.push({
    path: '/',
    redirect: '/home'
  })
  routes.push({
    path: '*',
    component: () => import('pages/Error404.vue')
  })
}

export default routes
