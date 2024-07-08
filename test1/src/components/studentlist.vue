<script>
    export default{
        data(){
            return{
				dialogVisible:false,
				singleDelete:false,
				editVis:false,
				row:{},
				currentAll:[],//当前所有学生的数据
                student:[],//返回数据
                checkData:[],//多选删除
                input:''//筛选条件
            }
        },
        methods: {
            edit(){
                console.log("editing")  
            },
			isDelete(row){
				this.row=row
				this.singleDelete=true
			},
			singlechoiceYes(){
				this.singleDelete=false
				this.deleteRow()
			},

            deleteRow(){
                console.log(this.row.account_id)  
				var that=this
				console.log(typeof(this.row.account_id))
				that.$http.delete("/consultant/v1/"+that.row.account_id).then(res=>{
					console.log(res)
					console.log(res.data)
				})
				
            },
			
            find(){			
                console.log("条件查询")
				console.log(this.input)
				if(!this.input|| !Number.isInteger(parseInt(this.input))){
					alert("数据错误，请重新输入")
					console.log("数据错误")
					this.student=this.currentAll
					return
				}
				var that=this
				var str='consultant/v1/'+this.input
				this.$http.get(str).then(res=>{
				    console.log(res.data)
					console.log(typeof(res.data))
					var temp=[]
					temp.push(res.data)
				    that.student=temp
				}).catch(res=>{
					console.log(res)
					
				})
            },
				
			choiceYes(){
				this.dialogVisible=false;
				this.selectDelete()
			},
			
            selectDeleteCall(){
				this.dialogVisible=true         
            },			
			
			selectDelete(){
				if(this.checkData.length===0){
					console.log("需要删除的内容为空")
					alert("请选择需要删除的数据")
					return 
				}else{
					
					const newArr = this.checkData.map(item => item.account_id);
					newArr.forEach(element=>{
						this.$http.delete("/consultant/v1/"+element).then(res=>{
							console.log(res.data)
						})
					})
					
				}
			},
			change(){
				console.log("开始修改数据")
				this.editVis=true
				console.log(this.editVis)
			},
			
            handleSelectionChange(val){
                this.checkData=val						
            },
				
			reset(){
				var that =this
				this.input=""
				this.$http.get("/consultant/v1").then(res=>{
				    that.student=res.data
					that.currentAll=res.data
				})
			}
        },
		
        mounted(){
            var that =this
            this.$http.get("/consultant/v1").then(res=>{
                console.log(res.data)
                that.student=res.data
				that.currentAll=res.data
            })
        }
    } 
</script>

<template>
    <el-card style="max-width: 1000px">
        <template #header>
            <div class="card-header">
                <div> 
                     <el-input v-model="input" style="width: 240px" placeholder="Please input"   />  &nbsp  
                     <el-button class='button' type="primary" @click='find' round>查询</el-button>
                </div>
                <div> 
                     <el-button  type="danger"  @click='selectDeleteCall' round>删除</el-button>
					 <el-button  type="success"  @click='reset()' round>重置</el-button>
                </div>
            </div>
        </template>
 
          <el-table ref="multipleTableRef" :data="student" style="width: 100%" @selection-change="handleSelectionChange">
              <el-table-column type="selection" width="60" />
          
              <el-table-column fixed prop="account_id" label="account_id" width="150" />
              <el-table-column prop="consult" label="consult" width="150" />
              <el-table-column prop="balance" label="balance" width="150" />
			  <el-table-column prop="cost_per_hour" label="cost_per_hour" width="150" />
              <el-table-column prop="password" label="password" width="200" />
              <el-table-column fixed="right" label="Operations" min-width="200">
                  <template #default="scope">
                      <el-button link type="primary" size="small" @click="isDelete(scope.row)">
                          delete
                      </el-button>
                      <el-button link type="primary" size="small" @click="change()">Edit</el-button>
                  </template>
              </el-table-column>
          </el-table>
        <template #footer>心理咨询师信息管理表</template>
  </el-card>
  
  
   <el-dialog
      v-model="dialogVisible"
      title="请再次确认"
      width="500"
     center
    > 
      <template #footer>
        <div class="dialog-footer">
          <el-button @click="dialogVisible = false">取消</el-button>
          <el-button type="primary" @click="choiceYes()">
            删除
          </el-button>
        </div>
      </template>
    </el-dialog>
	
	<el-dialog
	   v-model="singleDelete"
	   title="请再次确认"
	   width="500"
	  center
	 > 
	   <template #footer>
	     <div class="dialog-footer">
	       <el-button @click="singleDelete = false">取消</el-button>
	       <el-button type="primary" @click="singlechoiceYes()">
	         删除
	       </el-button>
	     </div>
	   </template>
	 </el-dialog>
	 
	 
	 
	 <el-dialog v-model="editVis" title="Shipping address" width="500">
	    <el-form :model="student">
	      <el-form-item label="Promotion name" :label-width="formLabelWidth">
	        <el-input v-model="student.student_ID" autocomplete="off" />
	      </el-form-item>
	    </el-form>
	    <template #footer>
	      <div class="dialog-footer">
	        <el-button @click="editVis = false">Cancel</el-button>
	        <el-button type="primary" @click="editVis = false">
	          Confirm
	        </el-button>
	      </div>
	    </template>
	  </el-dialog>
	 
	 
	
</template>





<style>
    .card-header{
        display:flex;
        justify-content:space-between
    }



</style>