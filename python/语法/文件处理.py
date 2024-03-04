#
f = open("data.txt", "r", encoding ="utf-8")
#print(f.read())#读取文件的所有内容
#print(f.readline())按行读取
#print(f.readlines()) 全部按行读取，得到列表
lines=f.readlines()
for line in lines:
    print(line)
f.close()

with open("demo.txt", "a", encoding="utf-8") as f:
    f.write("我欲乘风归去\n")
    f.write("又恐琼楼玉宇\n")
    

