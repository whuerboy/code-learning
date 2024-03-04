from  数据获取 import  count3   #数据获取
from  pyecharts.charts.basic_charts.bar import  Bar #作图
bar=Bar()#做柱状图
list=[] #x轴
lname=[] #y轴
j=0
for i in count3.values:
    if(j<15):
        list.append(int(i)) #获取出演的次数,y轴
        lname.append(str(count3.index[j])) #获取演员 ，x轴
        j=j+1
print(list)
print(lname)
bar.add_xaxis(lname)
bar.add_yaxis("演员出演次数",list)
