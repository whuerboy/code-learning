import  requests
from bs4 import  BeautifulSoup
header = {
    "User-Agent":"Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Mobile Safari/537.36 Edg/118.0.2088.61"
}
response = requests.get("http://books.toscrape.com/",headers=header).text
soup = BeautifulSoup(response,"html.parser")
all_price = soup.find_all("p",attrs={"class":"price_color"})
book = []
prices = []


all_name = soup.find_all("h3")
for name in all_name:
    links = name.findAll("a")
    for link in links:
        print(link.string)
        book.append(link.string)

for price in all_price:
    print(price.string[2:])
    prices.append(price.string)

f = open("书名",'a',encoding="utf-8")
for times in range(0,len(book)):
    f.write(book[times])
    f.write("  ")
    f.write(prices[times])
    f.write("\n")

f.close()
response.close()