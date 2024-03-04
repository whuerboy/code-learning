class Employee:
    def __init__(self,name,id):
        self.name = name
        self.id = id

    def print_info(self):
        print(f"姓名：{self.name},工号:{self.id}")

    def calculate_monthly_pay(self):
        print("月薪为：0元")


#继承：
class FullTimeEm(Employee):
    def __init__(self,name,id,salary):
        super().__init__(name,id)
        self.monthly_salary = salary

    def calculate_monthly_pay(self):
        print(f"{self.name}月薪为：{self.monthly_salary}元")

class DayTimeEm(Employee):
    def __init__(self,name,id,salary,work_days):
        super().__init__(name,id)
        self.daily_salary = salary
        self.work_days = work_days

    def calculate_monthly_pay(self):
        print(f"{self.name}月薪为：{self.daily_salary*self.work_days}元")

Ming = FullTimeEm("小明","123456",10000)
Hong = DayTimeEm("小红","789456",30,20)
Ming.print_info()
Ming.calculate_monthly_pay()
print()
Hong.print_info()
Hong.calculate_monthly_pay()