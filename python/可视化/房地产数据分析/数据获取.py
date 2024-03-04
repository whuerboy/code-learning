import pandas as pd
import numpy as np

djs = pd.read_csv("安居客租房信息.csv")

# 检查是否存在缺失值，有的话就删去所在行
djs.isnull().any()
djs.dropna(axis=0,how='any',inplace=True)

#重命名某些列以提高可读性
# djs=djs.rename(columns={'户型':'户型/室',
#                               '户型1':'户型/厅',
#                               '房屋面积':'房屋面积/平米',
#                               '轨道交通':'轨道交通/号线'
#                               })



towords = djs["朝向"].values #将表中“朝向”的数据取出来
print(towords)


#这一步可以不用因为每个房子就只有一个朝向
# list_towords=np.array([x.split('、') for x in towords])
# result=list_towords.flatten()

series=pd.Series(towords)
count=series.value_counts()
print(count)
