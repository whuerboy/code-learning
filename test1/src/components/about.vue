<script>
    export default{
        data(){
            return{
                student:[]
            }
        },
        mounted(){
            var that =this
            this.$http.get("/v1/stu").then(res=>{
                console.log(res.data)
                that.student=res.data
            })
        }
    } 
</script>

<template>
     <div class="common-layout">
        <el-container class="layout-container-demo" style="height: 500px">
        
            <el-header>Header</el-header>
                <el-container>
                    <el-aside width="200px" class="side">                   
                        <el-menu default-active="2" class="el-menu-vertical-demo" @open="handleOpen"  @close="handleClose">

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
                    </el-aside>

                    <el-main> <Routerview></Routerview> </el-main> 

                </el-container>

         </el-container>
     </div>
</template>

<style>

</style>