<template>

    <el-col :span="23" >

      <el-menu
        default-active="2"
        class="el-menu-vertical-demo"
        @open="handleOpen"
        @close="handleClose"
      >
            <el-menu-item index="1">
                <el-icon><House /></el-icon>
                <span>管理信息</span>
            </el-menu-item>
    

            <el-menu-item index="2">
                <el-icon><icon-menu /></el-icon>
                <span><RouterLink to='/stu'>用户信息管理 </RouterLink></span>
            </el-menu-item>

            <el-menu-item index="3" >
                <el-icon><document /></el-icon>
                <span><RouterLink>咨询师信息管理 </RouterLink></span>
            </el-menu-item>

            <el-menu-item index="4">
                <el-icon><setting /></el-icon>
                <span><RouterLink>设置 </RouterLink></span>
            </el-menu-item>
      </el-menu>
    </el-col>
   
</template>

<script lang="ts" setup>
import {
  Document,
  Menu as IconMenu,
  Location,
  Setting,
} from '@element-plus/icons-vue'

    const handleOpen = (key: string, keyPath: string[]) => {
        console.log(key, keyPath)
    }
    const handleClose = (key: string, keyPath: string[]) => {
        console.log(key, keyPath)
    }
</script>