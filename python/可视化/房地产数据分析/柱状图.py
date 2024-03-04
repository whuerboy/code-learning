
from pyecharts import options as opts
from pyecharts.charts import *
from pyecharts.charts import  Page
from  数据获取  import  count
from pyecharts.charts.basic_charts.bar import  Bar
bar1 =Bar()
bar2=Bar()#定义两个柱形图的容器
xlist=count.index.tolist()
ylist=count.values.tolist() #tolist（）将数据转为int类型的列表，才可以用于pyecharts显示

x1=[]
x2=[]
y1=[]
y2=[]
#分开定义

#图表的数据分类，大的放进x1,y1，少的放进x2,y2
for i in range(0,len(xlist)):
    if ylist[i]>1000:#朝向房子数目很多
        y1.append(ylist[i])
        x1.append(xlist[i])
    else:
        y2.append(ylist[i])
        x2.append(xlist[i])


print(xlist)
print(ylist)
print(x1)
print(y1)
#bar1画的是朝向较多的图
bar1.add_xaxis(x1)
bar1.add_yaxis("朝向多",y1,itemstyle_opts=opts.ItemStyleOpts(color="pink"))#最后一个参数是设置柱子的颜色
bar1.set_global_opts(
    title_opts=opts.TitleOpts(title="各个朝向房子数量图1",subtitle="朝向数量大于1000的房子", pos_left = '80%'),#设置主标题和副标题，并且将标题放在右边
    yaxis_opts=opts.AxisOpts(name="房子的数量"),#设置y轴的名称
    xaxis_opts=opts.AxisOpts(name="房子的朝向")#设置x轴的名称
)
bar1.set_series_opts(
    label_opts=opts.LabelOpts(is_show=True)#是否显示柱形图的数据，True为显示
)
#bar2画朝向较少的图
bar2.add_yaxis("朝向少",y2)
bar2.add_xaxis(x2)
bar2.set_global_opts(
    title_opts=opts.TitleOpts(title="各个朝向房子数量图2", subtitle="朝向数量小于1000的房子",pos_left = '80%'),#设置主标题和副标题，并且将标题放在右边
    yaxis_opts=opts.AxisOpts(name="房子的数量"),#设置y轴的名称
    xaxis_opts=opts.AxisOpts(name="房子的朝向")#设置x轴的名称
)
bar2.set_series_opts(
    label_opts=opts.LabelOpts(is_show=True) #是否显示柱形图的数据，True为显示
)

page=Page()#定义一个页面
page.add(bar1,bar2)#将这两个图放在页面里面
page.render("朝向柱形图.html")#生成网页显示页面