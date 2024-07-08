<script >
    export default{
        data(){
            return{
                student:[],
                name: 'App'
            }
        }
    } 
</script>

<template>
     <div class="common-layout">
        <el-container  >    
            <el-header>Header</el-header>
                <el-container>
                    <el-aside width="200px" >   
                        <el-col :span="22">                
                        <el-menu default-active="2" class="el-menu-vertical-demo" >
                            <!-- <el-menu-item index="1">
                                <el-icon><House /></el-icon>
                                <span>管理信息</span>
                            </el-menu-item> -->
                    
                            <el-menu-item index="2">
                                <el-icon><icon-menu /></el-icon>
                                <span><router-link to='/stu' style="text-decoration: none;color: black; " >咨询师信息管理 </router-link></span>
								
                            </el-menu-item>

                            <el-menu-item index="3" >
                                <el-icon><icon-document /></el-icon>
                                <router-link to ='/user' style="text-decoration: none;color: black;">用户信息管理 </router-link>
                            </el-menu-item>

                            <el-menu-item index="4">
                                <el-icon><setting /></el-icon>
                                <span><router-link to ='/person' style="text-decoration: none;color: black;">设置 </router-link> </span>
                            </el-menu-item>
                        </el-menu>    
                    </el-col>                               
                    </el-aside>	
									
					<el-main> <router-view> </router-view> </el-main> 
					
                </el-container>

         </el-container>
     </div>
</template>

<style>

</style>