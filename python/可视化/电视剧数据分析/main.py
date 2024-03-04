from 柱状图pyecharts import  bar
from  饼图表pyecharts import  pie
from  pyecharts.charts import  Page
page=Page()
page.add(bar,pie)
page.render("主图.html")