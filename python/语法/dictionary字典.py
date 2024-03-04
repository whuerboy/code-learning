#dictionary 储存键值对的数据结构
#创建空的字典

#dict.keys() 所有键
#dict.values() 所有值
#dict.items() 所有键值对

dict={"小明":18169718244,
      "小红":17386123996}
dict["小方"] = "我的世界因为有你才精彩"
#dict[11] = "你想干什么" 键的类型应该一样，否则就算没有报错，dict里面也没有键为11的键值对
qurey = input("请输入您要查询的词： ")

if qurey in dict:
    print(dict[qurey])
else:
    print("您要查询的词条不在字典中")
    print("当前字典中的词条的对数:"+str(len(dict)))

dictplus = {("小明",'男'):18169718244}
dictplus[("小明","女")] = "这个小明是女的"
print(dictplus[("小明","女")])
print(dictplus[("小明",'男')])