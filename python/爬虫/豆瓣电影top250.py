
import requests
from bs4 import  BeautifulSoup

#爬虫爬取网页的步骤：首先先向网页的服务器发送获取信息的请求，服务器会将你所需要的信息返还给你，需要一个列表来接收，剩下的就是对信息的筛选和处理了。






header = {
    "User-Agent":"Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Mobile Safari/537.36 Edg/118.0.2088.61"
}#伪装成浏览器
file = open("file.txt","a",encoding = "utf-8")
for start_num in range(0,250,25):

    response = requests.get(f"https://movie.douban.com/top250?start={start_num}",headers=header)
    print(response.status_code)
    content = response.text
    soup = BeautifulSoup(content,"html.parser")#解析html网页结构
    all_title = soup.findAll("span",attrs = {"class":"title"})
    # for title in all_title:
    #     print(title.string)



    for title in all_title:
            str_title = title.string
            if "/" not in str_title:
                file.write(str_title)
                file.write("  ")
                print(str_title)
    file.write("\n")
file.close()
response.close()