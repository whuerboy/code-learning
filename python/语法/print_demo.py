import math

print("hello")
print("hello"," world"+"  你好")
print("""君不见黄河之水天上来
君不见高堂明镜悲白发""")
greet = "hello what'up"
print(greet + ' zhangsan')
print(math.sin(50))

user_height = float(input("请输入您的身高(m) "))
user_weight = float(input("请输入您的体重（kg） "))
user_BMI  = float(user_weight)/float(user_height)**2
print(user_BMI)

if user_BMI<=18.5:
    print("很好达到了平均身高")
elif 18.5<user_BMI<=25:
    print("坏了")
else:
    print("很坏")















