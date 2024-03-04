import re
import requests

url='https://www.btwuji.com/'
url_list=[]
response1=requests.get(url)
response1.encoding='gb2312'

c=re.compile(r"最新发布180部影视.*?"
           r"<a href='/html/gndy/jddy/20160320/50510.html'>IMDB评分8分左右影片400余部</a><br/>(?P<context>.*?)</ul>",re.S)
c1=re.compile(r"<a href='(?P<url>.*?)'>",re.S)
c2=re.compile(r'<div class="title_all"><h1>.*?>(?P<name>.*?)<.*?'
              r'磁力链下载器：<a href="(?P<down1>.*?)".*?'
              r'播放软件下载：<a href="(?P<down2>.*?)"',re.S)
result = c.finditer(response1.text)
response1.close()
for it in result:

    result1 = c1.finditer(it.group("context"))

for it in result1:
    url_list.append(it.group("url"))

file=open("get.txt","w",encoding="gbk")
for subUrl in url_list:
    sonUrl=url+subUrl.strip('/')
    response2=requests.get(sonUrl)
    response2.encoding='gbk'
    result3=c2.search(response2.text)
    file.write("电影名：")
    file.write(result3.group("name"))
    file.write('\n')
    file.write("   磁力下载链接： ")
    file.write(result3.group("down1"))
    file.write('\n')
    file.write("   播放软件下载链接： ")
    file.write(result3.group("down2"))
    file.write('\n')
    file.write('----------------------------------------')
    file.write('\n')
    response2.close()

file.close()



