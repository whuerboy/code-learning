from pyecharts.charts.basic_charts.pie import Pie #饼状图
from pyecharts.options import TitleOpts, LegendOpts
from pyecharts.options import LabelOpts
from 数据获取 import count2

#
# bar.add_xaxis(["衬衫","羊毛衫","雪纺衫","裤子"])
# bar.add_yaxis("商家",[5,20,15,8])
# bar.render_notebook()
# bar.render()
pie = Pie()#做饼状图
list1=[]
j=0
for i in count2.values:
   if j<15:
        m=float(i*100)
        list1.append(round(m,2))
        j=j+1

j=0
lname=[]
for i in count2.index:
    if j<15:
        lname.append(str(i))


# list1=[]
# lname=[]


pie.add(
    "name ",
    [ list(z) for z in zip( lname,list1)],
    center=["50%", "50%"]
)

pie.set_global_opts(

    title_opts=TitleOpts(title="演员演出次数（前15）饼状图",pos_top="True"),

    #图例配置：
    legend_opts=LegendOpts(is_show=True,pos_left="80%", orient="vertical") #将图标放在右侧

)

pie.set_series_opts(
    label_opts=LabelOpts(formatter="{b}:{c}%")  #配置显示模式
)

