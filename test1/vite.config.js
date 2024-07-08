import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'

import AutoImport from 'unplugin-auto-import/vite'
import Components from 'unplugin-vue-components/vite'
import { ElementPlusResolver } from 'unplugin-vue-components/resolvers'

export default defineConfig({
  // ...
  plugins: [
    // ...
    AutoImport({
      resolvers: [ElementPlusResolver()],
    }),
    Components({
      resolvers: [ElementPlusResolver()],
    }),
    vue(),
  ],
})

// const AutoImport = require('unplugin-auto-import/webpack');
// const Components = require('unplugin-vue-components/webpack');
// const { ElementPlusResolver } = require('unplugin-vue-components/resolvers');
// module.exports = {
//   configureWebpack: {
//     resolve: {
//       alias: {
//         components: '@/components'
//       }
//     },
//     //配置webpack自动按需引入element-plus，
//     plugins: [
//       AutoImport({
//         resolvers: [ElementPlusResolver()]
//       }),
//       Components({
//         resolvers: [ElementPlusResolver()]
//       }),
//       vue()
//     ]
//   }
// };




