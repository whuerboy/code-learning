// pages/my/my.js
Page({
  shuoming:function(){
    wx.reLaunch({
      url:'/pages/my/shuoming/shuoming'
    })
  },//点击使用说明实现界面跳转
  jisuan:function(){
    wx.reLaunch({
      url:'/pages/my/jisuan/jisuan'
    })
  },
 fankui:function(){
    wx.reLaunch({
      url:'/pages/my/fankui/fankui'
    })
  },

 
  data: { loginOk:false,
    //昵称
    nickName:"",
    //头像
    avatarUrl:"",

    isLogin: false ,// 判断用户是否已登录，默认为未登录
    shows:false,
   
    day:'',
    Number:0,
    List:''
  },
  loadByWechat(){
    wx.getUserProfile({
      desc: '用户完善会员资料',
    })
      .then(res=>{
        console.log("用户允许了微信授权登录",res.userInfo);
        //保存用户登录信息到缓存
        wx.setStorageSync('userInfo', res.userInfo);
        this.setData({
          loginOk:true,
          nickName:res.userInfo.nickName,
          avatarUrl:res.userInfo.avatarUrl
        })
     })
     .catch(err=>{
       console.log("用户拒绝了微信授权登录",err);
   })
  },
  
  exit(){
    wx.showModal({
    content:"确定退出吗"
   }).then(res=>{
    if(res.confirm){
    console.log("用户点击了确定");
    this.setData({
      loginOk:false
    })
      //清空登录的缓存
      wx.setStorageSync('userInfo', null)
    }else if(res.cancel){
    console.log("用户点击了取消");
    }
    })
  },

});