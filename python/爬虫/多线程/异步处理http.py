#request.get(),post()是同步操作，不能进行协程处理

import asyncio
import aiohttp
import time

import requests

urls=[
    'https://i1.huishahe.com/uploads/tu/202206/6/61c976a82d.jpg',
    'https://i1.huishahe.com/uploads/tu/202205/19/e462258db6.jpg',
    'https://i1.huishahe.com/uploads/tu/201911/9999/rn67282cef46.jpg'
]

async  def download(url):
    #aiohttp.ClientSession <==>request

    name=url.split('/')[-1]
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as resp:
            with open(name,mode='wb') as f:
                f.write(await resp.content.read())  #读取内容是异步的，需要挂起。
            # print(resp.text())
            # print(resp.json())


async  def main():
    task = []
    for url in urls:
        task.append(asyncio.create_task(download(url)))
    await asyncio.wait(task)

if __name__ == '__main__':

    start = time.time()
    asyncio.run(main())
    print(time.time()-start)
#异步处理：用时1s



# 非异步处理：用时3s
# start = time.time()
# for url in urls:
#     rep=requests.get(url)
#     name=url.split('/')[-1]
#     with open(name,mode='wb') as f:
#         f.write(rep.content)
# print(time.time()-start)