import  requests
# name=input("输入您要查询的人物")
# url = f'https://cn.bing.com/search?q={name}'
# headers = {
#     "authority":"cn.bing.com",
#     "User-Agent":"Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Mobile Safari/537.36 Edg/120.0.0.0"
# }
# reponse=requests.get(url,headers=headers)
# str=reponse.text
# print(str)
# #将返回的信息打印到html文件中
# with open("myHtml.html",mode="w",encoding="utf-8") as f:
#     f.write(str)


# 当网页是post的方式进行传递数据时，则查找的内容则不能直接放url里面，而是通过字典来传参数

url1='https://fanyi.baidu.com/sug'
context = input("输入要翻译的单词")
dict={
    "kw":context
}
reponse1=requests.post(url1,data=dict)
print(reponse1.json())
reponse1.close()