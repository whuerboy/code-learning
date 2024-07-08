<script setup>
import { ref } from 'vue'

defineProps({
  msg: String,
})

const count = ref(0)
</script>

<template>
  <h1>{{ msg }}</h1>
  <router-link to='/home'>homepage</router-link> 
  &nbsp;&nbsp;&nbsp;&nbsp;
  <router-link to='/about'>aboutpage</router-link>
<hr>
  <router-view ></router-view>
  <div class="card">
    <button type="button" @click="count++">count is {{ count }}</button>
   
  </div>



</template>

<style scoped>
.read-the-docs {
  color: #888;
}
</style>
