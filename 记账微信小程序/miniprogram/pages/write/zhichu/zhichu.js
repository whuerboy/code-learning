// pages/zhichu/zhichu.js
Page({

  /**
   * 页面的初始数据
   */
  data: {

  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {

  }
})
Component({
  // 使自定义组件有类似于表单控件的行为
  behaviors: ['wx://form-field'],
  /**
   * 组件的属性列表
   */
  properties: {
      value:{//这里的属性名之所以取名value是因为表单控件有name和value属性
          type:String,
          value:"1"
      }
  },

  /**
   * 组件的初始数据
   */
  data: {
      currentIndex:1
  },

  /**
   * 组件的方法列表
   */
  methods: {
      point(e){
          const {index}=e.currentTarget.dataset;
          if(index==1){
              this.setData({//properties和data里的值都可用setData设置
                  value:"1",
                  currentIndex:1
              })
          }
          else if(index==2){
              this.setData({
                  value:"2",
                  currentIndex:2
              })
          }
          else if(index==3){
            this.setData({
                value:"3",
                currentIndex:3
            })
        }
        else if(index==4){
          this.setData({
              value:"4",
              currentIndex:4
          })
      }
      else if(index==5){
        this.setData({
            value:"5",
            currentIndex:5
        })
    }
    else if(index==6){
      this.setData({
          value:"6",
          currentIndex:6
      })
  }

      }
  }
})