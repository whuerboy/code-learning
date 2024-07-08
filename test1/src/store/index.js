import { createStore } from "vuex"


const store = createStore({
    state () {
      return {
        username:"messi",
        count: 0
      }
    },
    mutations: {
      increment (state) {
        state.count++
      }
    }
  })

  export default store