#列表是可变的，且可以存放不同类型的数据
shop_list = None;
print(type(shop_list))
shop_list = ['键盘']
shop_list.append("鼠标")
shop_list.append("蓝牙耳机")
print((type(shop_list)))
print(shop_list)
shop_list.remove('鼠标')
print(shop_list)
shop_list.clear()
print(shop_list)

price = [1000,2000,100,500]
print(max(price))
print(min(price))
print((sorted(price)))