from urllib.request import  urlopen
url="http://www.baidu.com"
reponse=urlopen(url)
str=reponse.read().decode("utf-8")
print(str)
#将返回的信息打印到html文件中
with open("myHtml.html",mode="w",encoding="utf-8") as f:
    f.write(str)
reponse.close()