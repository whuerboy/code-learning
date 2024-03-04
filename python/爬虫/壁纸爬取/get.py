import requests
from bs4 import  BeautifulSoup
import time
import asyncio
import aiohttp


async  def aiodownload(url,name):
    #aiohttp.ClientSession <==>request

    async with aiohttp.ClientSession() as session:
        async with session.get(url) as resp:
            with open(name,mode='wb') as f:
                f.write(await resp.content.read())  #读取内容是异步的，需要挂起。
                f.close()
            # print(resp.text())
            # print(resp.json())


async  def main1():
    task = []
    count=0
    for url in urls:
        task.append(asyncio.create_task(aiodownload(url,names[count])))
        count = count+1
    await asyncio.wait(task)


def download(url,name):
    response2=requests.get(i.get('data-original'))
    with open(name,mode="wb") as file: #写的时候用的是字节写
        file.write(response2.content)



def main2():
    count = 0
    for url in urls:
        download(url,names[count])
        count=count+1



if __name__ == '__main__':

    url="http://m.umeituku.com/bizhitupian/weimeibizhi/"
    response1=requests.get(url)
    response1.encoding='utf-8'
    soup=BeautifulSoup(response1.text,"html.parser")
    cont=soup.find("div",class_="pic-list pic-list-2 pic-list-shadow").find_all("img")
    start=time.time()

    urls=[]
    names=[]
    for i in cont:
        urls.append(i.get('data-original'))
        names.append("img/"+i.get('alt')+'.jpg')

    print('异步下载开始')
    start = time.time()
    asyncio.run(main1())
    print(f'异步下载用时：+{time.time()-start}s')
    print('------------------------------')
    print('同步下载开始')
    start = time.time()
    main2()
    print(f'同步下载用时：+{time.time()-start}s')






#同步处理共用时31s
#异步下载图片用时5.4s



