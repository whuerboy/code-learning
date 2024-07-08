import { createMemoryHistory, createRouter } from 'vue-router'

import Home from '../components/Home.vue'
import About from '../components/about.vue'
import Hello from '../components/HelloWorld.vue'
import Stu from '../components/studentlist.vue'
import Login from '../components/login.vue'
import User from '../components/UerList.vue'

import Person from"../components/person.vue"
import Menu from '../components/menu.vue'

const routes = [
  { path: '/', component: Login },
  
  { path: '/home', component:Home,children: [
	  {path:'/stu',component:Stu},
	  {path:'/user',component:User},
	  {path:'/person',component:Person}
  ] },
 
  {path:'/hello',component:Hello},

]

const router = createRouter({
  history: createMemoryHistory(),
  routes,
})

export default router