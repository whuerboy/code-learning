import pandas as pd
import numpy as np



dsj = pd.read_csv('电视剧.csv')#把表格数据读下

#将排序作作为索引
dsj.set_index('排名',inplace=True)
#print(dsj)
#
# #统计剧场类型各个占比
# print(dsj['剧场类型'].value_counts())
#
#
# #年份分组,分为2011之前和之后方方便统计
# # dsj['播出日期']=pd.to_datetime(dsj['播出日期'])
# # video1=dsj.loc[dsj['播出日期']>=pd.to_datetime('2011.1.1')]
# # video2=dsj.loc[dsj['播出日期']<pd.to_datetime('2011.1.1')]
# # print(video1)
# # print(len(video1))
# # print(video2)
# # print(len(video2))
#
#
#
# #统计标签占比：
# print(dsj['标签'].value_counts())
# #统计每一个单独的标签的个数：
# bq=dsj['标签'].values
# tip_2d = np.array([x.split('、') for x in bq])   #将所有的标签都放到数组里面
# print(tip_2d)
# tip_1d = tip_2d.flatten()   #此时并没有合并重复的内容
# #flatten是numpy.ndarray.flatten的一个函数，即返回一个折叠成一维的数组。但是该函数只能适用于numpy对象，即array或者mat，普通的list列表是不行的
# #print(tip_1d)
# series1 = pd.Series(tip_1d) #此时有没有合并重复内容
# # print(tip_1d[299])
# # print(series1[299])
# count1 = series1.value_counts()
#
# print(count1)
# print(type(count1))
# print(count1.values)
# print(type(count1.values))
# print(count1.index[0])
#
# list1=[]
# lname1=[]
# list1 = count1.values.tolist()
# lname1 = count1.index.tolist()
# # for j in count1.index:
# #     lname.append(str(j))


#统计每一个主演演员上榜的次数
zy = dsj['主演'].values
lst_2d = list(x.split('、') for x in zy)
print(lst_2d)
lst_1d = []
for v in lst_2d:
    for w in v:
        lst_1d.append(w)
series2=pd.Series(lst_1d)
count2 = series2.value_counts(normalize=True) #需要注意一点value_counts函数返回值类型是series
count3= series2.value_counts()

print(count3)
print(count2)
#统计主演和标签使用不同的方法是因为主演的数组长度会变，不能使用flatten函数压缩，只能采取列表的遍历手动压缩，而每个电视剧的标签都是三个
# list2=[]
# lname2=[]
# list2=count2.values.tolist()
# lname2 = count2.index.tolist()
# print(count2.index)
# print(count2.values)


#对列表做中位数，平均数等数据处理
#print(dsj.describe())


