#for 变量名 in 可迭代对象
temp_list=[100,200,35,20.11,10,9,8]
num_of_high = 0
for temp in temp_list:
    if(temp>30):
        print("要死人了")
        num_of_high = num_of_high+1
print("发烧的人数:"+str(num_of_high))

#rang(4,10) 产生应该整数的序列，从4到9,第三个参数为步长，不设置时默认值为1
for num in range(0,101):
    print(num)