# 字符串的初始化：
contact = ["小明","小红",'小方']
year = "虎"

# for name in contact:
#    print( "恭喜{0}，祝您在{1}年蒸蒸日上".format(name,year))

#format 初始字符串有很多种格式
for name in contact:
   print( "恭喜{user_name}，祝您在{year}年蒸蒸日上".format(user_name=name,year=year)) #第一个是变量名，后面是变量的值

gpa_list={"小明":3.17,"小红":3.56,"小方":3.99}
# for name,gpa in gpa_list.items():
#     print("{0}你好，您的gpa为：{1:.1f}".format(name,gpa))  #保留1位小数输出gpa


# f修饰的字符串也可以格式化
for name,gpa in gpa_list.items():
    print(f"{name}你好，您的gpa为：{gpa:.1f}")  #保留1位小数输出gpa