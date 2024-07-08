<template>
	<el-row :gutter="50">
		<el-col :span="12" :offset="8">
			<el-card style="max-width: 480px">
				<el-form :model="form" label-width="auto" style="max-width: 600px">
					<el-form-item label=" 请输入账号名">
						<el-input v-model="user.name" maxlength="20" style="width: 240px" placeholder="Please input"
							show-word-limit type="textarea" />
					</el-form-item>
					<el-form-item label=" 请输入密码">
						<el-input v-model="user.password" maxlength="12" style="width: 240px" placeholder="Please input"
							show-word-limit type="textarea" />
					</el-form-item>
				</el-form>
			</el-card><br>
			<el-button type="primary" @click="submit"  > submit</el-button>
		</el-col>

	</el-row>
	&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp	
	&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
	&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
	&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
	&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
	&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
	&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
	&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
	<el-button plain @click="dialogFormVisible = true" type="primary">
	   创建新的管理员账号
	  </el-button>
	
	  <el-dialog v-model="dialogTableVisible" title="Shipping address" width="800">
	    <el-table :data="gridData">
	      <el-table-column property="date" label="Date" width="150" />
	      <el-table-column property="name" label="Name" width="200" />
	      <el-table-column property="address" label="Address" />
	    </el-table>
	  </el-dialog>
	
	  <el-dialog v-model="dialogFormVisible" title="Shipping address" width="500">
		  
	   <el-form :model="form" label-width="auto" style="max-width: 600px">
	   	<el-form-item label=" 请输入账号名">
	   		<el-input v-model="creater.name" maxlength="20" style="width: 240px" placeholder="Please input"
	   			show-word-limit type="textarea" />
	   	</el-form-item>
	   	<el-form-item label=" 请输入密码">
	   		<el-input v-model="creater.password" maxlength="12" style="width: 240px" placeholder="Please input"
	   			show-word-limit type="textarea" />
	   	</el-form-item>
	   </el-form>
		
	    <template #footer>
	      <div class="dialog-footer">
	        <el-button @click="dialogFormVisible = false">Cancel</el-button>
	        <el-button type="primary" @click="addAdmin()">
	          Confirm
	        </el-button>
	      </div>
	    </template>
	  </el-dialog>


</template>


<script>
	import {
		useRouter
	} from 'vue-router'
	export default {
		data() {
			return {
				dialogFormVisible:false,
				router: useRouter(),
				user:{ 
					
				},
				creater:{
					
				}
				
			}
		},

		methods: {
			
			addAdmin(){
				
				console.log(this.user);
				var isLogin = false;
				var that = this;
				var params = {
				  name: this.creater.name,
				  password: this.creater.password
				};
				console.log(params)
					
				if(!this.creater.name){
					alert("未填写账号名，请重新输入")
					return
				}
				if(!this.creater.password){
					alert("密码未填写")
					return
				}
				var queryString = new URLSearchParams(params).toString();
				this.$http.get("/login/v2/create",{ params }).then(res => {
					// 检查响应数据
					console.log(res)
					if (res.data === 400) {
						alert("管理员不存在");
						return; // 如果数据错误，提前返回，不执行后续代码
					}else if(res.data===100){
						alert("密码不正确")
						return;
					}
					else{
						// 使用 that.router 以确保作用域正确
						that.dialogFormVisible=false
						that.$router.push({
							path: '/home'
						});
					}
					
				}).catch(error => {
					console.error("请求失败", error);
				});
			},
			submit() {
				
				console.log(this.user);
				var isLogin = false;
				var that = this;
				var params = {
				  name: this.user.name,
				  password: this.user.password
				};
					
				if(!this.user.name){
					alert("未填写账号名，请重新输入")
					return
				}
				if(!this.user.password){
					alert("密码未填写")
					return
				}
				var queryString = new URLSearchParams(params).toString();
				this.$http.get("/login/v2",{ params }).then(res => {
					// 检查响应数据
					console.log(res)
					if (res.data === 400) {
						alert("管理员不存在");
						return; // 如果数据错误，提前返回，不执行后续代码
					}else if(res.data===100){
						alert("密码不正确")
						return;
					}
					else{
						// 使用 that.router 以确保作用域正确
						that.$router.push({
							path: '/home'
						});
					}
					
				}).catch(error => {
					console.error("请求失败", error);
				});
			}

			
		}
	}
</script>

<style>
	.el-row {
		margin-bottom: 20px;
	}

	.el-row:last-child {
		margin-bottom: 0;
	}

	.el-col {
		border-radius: 4px;
	}

	.grid-content {
		border-radius: 4px;
		min-height: 36px;
	}
</style>