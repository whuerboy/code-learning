#梨视频对真正的下载视频的地址进行的虚假处理，要拿到真正的下载地址需要contId和systemTime这两个参数

import requests
from lxml import etree
from bs4 import  BeautifulSoup
from concurrent.futures import ThreadPoolExecutor 

#拿到contID--->拿到videoStatus返回的json--->对srcUrl的内容进行修改---->下载视频

def fun(pageurl,count):
    url =pageurl+count
    countID=count.split('_')[1]
    jsonUrl=f'https://www.pearvideo.com/videoStatus.jsp?contId={countID}&mrd=0.5801978230422251'
    headers={
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36 Edg/121.0.0.0',
        'Referer':url  #防盗链，对请求源头进行溯源
    }

    reponse=requests.get(jsonUrl,headers=headers)
    json=reponse.json()
    videoUrl=(json['videoInfo'])['videos']['srcUrl']
    systemTime=json['systemTime']
    videoUrl=videoUrl.replace(systemTime,f'cont-{countID}')


    #获取视频名字
    re=requests.get(url)
    element=etree.HTML(re.text)
    name=element.xpath('//*[@id="detailsbd"]/div[1]/div[2]/div/div[1]/h1/text()')


    file=f'C:/Users/18251/Desktop/梨视频爬取/{name[0]}.mp4'
    with open(file,mode="wb") as f:
        get=requests.get(videoUrl)
        f.write(get.content)
        print('视频下载成功')

    reponse.close()
    re.close()



if __name__ == "__main__":
    #批量下载：
    pageurl='https://www.pearvideo.com/'
    request=requests.get(pageurl)
    bsoup=BeautifulSoup(request.text,'html.parser')
    url=(bsoup.find_all('a',attrs={"class":'vervideo-lilink actplay'}))
    countIDs=[]
    for r in url:
        a=r.attrs
        str=a['href']
        countIDs.append(str)
    with ThreadPoolExecutor(5) as t: #线程池
        for countid in countIDs:
            t.submit(fun,pageurl=pageurl,count=countid)
    
    print("所有视频下载完成")




# pageurl='https://www.pearvideo.com/'
# request=requests.get(pageurl)
# bsoup=BeautifulSoup(request.text,'html.parser')
# url=(bsoup.find_all('a',attrs={"class":'vervideo-lilink actplay'}))
# countIDs=[]
# for r in url:
#     a=r.attrs
#     str=a['href']
#     countIDs.append(str)
# for count in countIDs:
#     url =pageurl+count
#     countID=count.split('_')[1]
#     jsonUrl=f'https://www.pearvideo.com/videoStatus.jsp?contId={countID}&mrd=0.5801978230422251'
#     headers={
#         'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36 Edg/121.0.0.0',
#         'Referer':url  #防盗链，对请求源头进行溯源
#     }

#     reponse=requests.get(jsonUrl,headers=headers)
#     json=reponse.json()
#     videoUrl=(json['videoInfo'])['videos']['srcUrl']
#     systemTime=json['systemTime']
#     videoUrl=videoUrl.replace(systemTime,f'cont-{countID}')


#     #获取视频名字
#     re=requests.get(url)
#     element=etree.HTML(re.text)
#     name=element.xpath('//*[@id="detailsbd"]/div[1]/div[2]/div/div[1]/h1/text()')


#     file=f'C:/Users/18251/Desktop/梨视频爬取/{name[0]}.mp4'
#     with open(file,mode="wb") as f:
#         get=requests.get(videoUrl)
#         f.write(get.content)
#         print('视频下载成功')

#     reponse.close()
#     re.close()
