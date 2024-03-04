import asyncio
import aiohttp
import requests
import json

async def ayndownload(name, cid):
    data={
        '%22book_id%22':'%22'+b_id+'%22',
        '%22cid%22':'%22'+b_id+'|'+cid+'%22',
        '%22need_bookinfo%22':'1'
    }
    url='http://dushu.baidu.com/api/pc/getChapterContent?data={%22book_id%22:%22'+b_id+'%22,%22cid%22:%22'+b_id+'|'+cid+'%22,%22need_bookinfo%22:1}'
    async with aiohttp.ClientSession() as seesion:
        async with seesion.get(url) as rep:
            result = await rep.json()
            text = result['data']['novel']['content']
            with open("章节/"+name+".txt",'w',encoding='utf-8') as f:
                f.write(text)


async def main():
    count = 0
    task = []
    for cid in cids:
        task.append(asyncio.create_task(ayndownload(nameids[count], cid)))
        count = count + 1
    await asyncio.wait(task)


if __name__ == '__main__':
    reponse = requests.get('http://dushu.baidu.com/api/pc/getCatalog?data={%22book_id%22:%224306063500%22}')
    context = reponse.json()
    b_id = '4306063500'
    nameids = []
    cids = []
    for i in context['data']['novel']['items']:
        nameids.append(i['title'])
        cids.append(i['cid'])
    asyncio.run(main())
    print('小说摘录完成')


# rep1=requests.get('http://dushu.baidu.com/api/pc/getChapterContent?data={%22book_id%22:%224306063500%22,%22cid%22:%224306063500|1569782246%22,%22need_bookinfo%22:1}')
# result=rep1.json()
# print(rep1.text)

