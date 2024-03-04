class Cat:
    def __init__(self,cat_name): #在此定于类的属性
        self.name = cat_name
    def getName(self):
        return self.name

cat1 = Cat("小明")
print(cat1.getName())