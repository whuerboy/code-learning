// import { createApp } from 'vue'
// import './style.css'
// import App from './App.vue'

// import router from './router/index.js'

// import axios  from 'axios'

// import ECharts from 'vue-echarts'
// import "echarts"

// import Store from './store/index.js'


// const app=createApp(App).component("e-charts",ECharts).use(Store).use(router).mount('#app')

// app.globalProperties.$http=axios
import { createApp } from 'vue'

import App from './App.vue'

import router from './router/index.js'
import axios from 'axios'
import ECharts from 'vue-echarts'
import "echarts"
import Store from './store/index.js'

axios.defaults.baseURL='http://localhost:8080'
const app = createApp(App)

app.config.globalProperties.$http = axios

app.component("e-charts", ECharts)
app.use(Store)
app.use(router)
app.mount('#app')
