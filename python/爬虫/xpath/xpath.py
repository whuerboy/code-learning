from lxml import  etree
import requests
import  pandas as pd

url= 'https://www.zbj.com/index2022/seo/service/searchservice?indexAlias=logo&size=20&pageNum=1&fromBizType=1&fromSite=1'
reponse=requests.get(url)
data=[]
data=reponse.json()
result=[]
for i in data:
    for j in reponse.json()[i]:
        result.append(j)
    break
lists=[]

with open('data.txt','w',encoding='utf-8') as f:

    for i in result:
        list=[]
        name=i['shopName']
        f.write('公司名称：'+name+'     ')
        price=(i['price'])['origin']
        f.write('价格：'+price+'    ')
        saleCount=(i['saleCount'])['origin']
        f.write(f'累计销量：{saleCount}')
        f.write('\n')
        list.append(name)
        list.append(price)
        list.append(saleCount)
        lists.append(list)

df=pd.DataFrame(lists,columns=['公司名','价格','累计销量'])
df.to_csv('data.csv',index=False)
