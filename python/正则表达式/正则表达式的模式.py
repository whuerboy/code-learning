import  re
text = "18251767861 电话：17386123996 座机：0775-36993996-0987"
print(re.findall(r'6',text))#r表示原始字符，即使出现了\n等也正常处理


#查找某一类字符
# print(re.findall(r'\d',text))#单个数字
# print(re.findall(r'\D',text))#非数字
# print(re.findall(r'\w',text))#找到非标点符合之外的
# print(re.findall(r'[1-5]',text))
# print(re.findall(r'[电话]',text))#找到一个就返回一个

# #寻找重复字符,而且这些字符要连续
# print(re.findall(r'\d+',text))
# print(re.findall(r'9+',text))# +可以重复找被修饰的字符
# print(re.findall(r'Q+',text))
# print(re.findall(r'\d?',text))#  ?表示0或者1个
# print(re.findall(r'\d*',text))#   *表示0个或者多个
# print(re.findall(r'\d{1,5}',text))# {}表示可以找到数字个数的范围，而且是连续的
#
#
# print(re.findall(r'\d{4}-\d{8}-\d{4}',text))#组合模式


# #多种情况寻找：
# print("电话号码如下:")
# print(re.findall(r'\d{4}-\d{8}-\d{4}|1\d{10}',text)) #  |表示满足任意条件的 而后面那个表示1开头的
# print(re.findall(r'\d{4}-\d{8}-\d{4} | 1\d{10}',text)) #不要又有空格
#
# #限定查找的位置： ^表示开头 $表示结尾
# print("电话号码如下:")
# print(re.findall(r'\d{4}-\d{8}-\d{4}$|^1\d{10}',text))  #只要末尾多一个空格都找不到座机号码
#
#
# #内部约束：寻找abb型的数据
# text = " abb cdd eff ade dsad"
# print(re.findall(r'\w{1}\w{1}\w{1}',text))
# print(re.findall(r'(\w{1})(\w{1})(\2)',text))#（\2）表示和第二个括号里的是数据一样才可以
#
# #寻找模式包含的子模式，每个子模式的字符是什么，各个子模式如何重复，是否有位置限制，是否有内部限制
#
# test = "1825176761@qq.com"
# print(re.findall(r'\d{3}\B',test))# \B表示不出现在单词的边界，而\b表示出现在单词的边界
# print(re.findall(r'(?!=@)(?#表示正则表达式的注释)\d+',test))



it=re.finditer(r'\d{3}\B',text)#获取迭代器
for i in it:
    print(i.group())

s=re.search(r'\d{3}\B',text) #找到一个并返回match对象，访问match数据需要gruop（）函数
print(s.group())

a=re.match(r'\d{3}\B',"10086,123")
print(a.group())

#正则表达式的预加载
obj=re.compile(r'\d{3}\B')
print(obj.match("10086,123"))


str = '<div class= "java"> 面向对象</div>'
o=re.compile(r'<div class= ".*?">(?P<xingzhi>.*?)</div>',re.S)
m=o.finditer(str)
for i in m:
    print(i.group("xingzhi"))