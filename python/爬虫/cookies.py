# cookies
#登录  ==》 得到cookies
#带着cookies去请求，相当于token，用于记录登录信息
#这两个操作是要连起来的，可以使用session进行操作，session是一连串的请求，在这个过程中cookies不会丢失

import  requests

session=requests.session()

response=session.get('https://user.17k.com/ck/author2/shelf?page=1&appKey=2406394919',headers={
    'Cookie':'GUID=a8663249-7281-4e23-8c84-190f66be68aa; acw_sc__v2=65c1985b2aba0add3d6cd4f55a6b19b7fc102175; sajssdk_2015_cross_new_user=1; c_channel=0; c_csc=web; Hm_lvt_9793f42b498361373512340937deb2a0=1707186282,1707187645; accessToken=avatarUrl%3Dhttps%253A%252F%252Fcdn.static.17k.com%252Fuser%252Favatar%252F08%252F88%252F44%252F103044488.jpg-88x88%253Fv%253D1707187774000%26id%3D103044488%26nickname%3D%25E5%25A6%2582%25E6%259D%25A5%25E4%25BD%259B%25E7%25A5%2596%25E4%25BB%25A3%25E7%25A0%2581%25E5%25BA%2593%26e%3D1722739793%26s%3D0d70d4967f0eed46; BAIDU_SSP_lcr=https://cn.bing.com/; sensorsdata2015jssdkcross=%7B%22distinct_id%22%3A%22103044488%22%2C%22%24device_id%22%3A%2218d7c3b5ffa72b-0436fca201dc67-4c657b58-1327104-18d7c3b5ffb10ff%22%2C%22props%22%3A%7B%22%24latest_traffic_source_type%22%3A%22%E8%87%AA%E7%84%B6%E6%90%9C%E7%B4%A2%E6%B5%81%E9%87%8F%22%2C%22%24latest_referrer%22%3A%22https%3A%2F%2Fcn.bing.com%2F%22%2C%22%24latest_referrer_host%22%3A%22cn.bing.com%22%2C%22%24latest_search_keyword%22%3A%22%E6%9C%AA%E5%8F%96%E5%88%B0%E5%80%BC%22%7D%2C%22first_id%22%3A%22a8663249-7281-4e23-8c84-190f66be68aa%22%7D; ssxmod_itna=Qq0OiK4+rxkKitDXDnAm30=D7R3bKei=k+eWbe=7DlEY3xA5D8D6DQeGTbcWekbtjgDoijY=DwAx=7E++d3Wt03uWFk0+r4GLDmKDyiGOPGGRxBYDQxAYDGDDpCDj4ibDYfzODjBItzZCq=D3qDwDB=DmqG2Kn=Dm4DfDDdyK7wK90=cDYQDGqDStnTxxD3Df3U=DDX=C1Yre4GWCMtXbC0Px1GM70=DjqGgDBdrKFTNo9B=SMtzOiFFiM0qxBQD7u2SDkrDCoUVRLQOq4fqixAemieHKBqYA7qIiowxerxYG7qZ2iheW7qKYGkxYH7qpRDxxq4D; ssxmod_itna2=Qq0OiK4+rxkKitDXDnAm30=D7R3bKei=k+eWbe=D66IY40HTw403oqye2W5gD6DoT=PFG=CT=r2WDjr6K5G1Db6srGUx9N4FP=n5m6Pfpny9UoEjZ0hvVWCB9K6VmkvYx69b9ij+f/OYK87fRfh+=WDK/fhDKNmEqa7w4kQx7bRIqFlRPcjIQRmY5hjNTh8WkWiRmK76dgDcVtnRqPPYk0Z05r+AxmgF7AAFqTbWgtKc5kn9wxUrKi6oWNuKBYbfLc187NlDSi1GtwearPrBCb+OgREinpM2fjE0vYzyc5U7u3=8AvQqQkb8xYR2Oh4Kg4hyrt+8kp3OEStg0hMu397D+Ai7qkWuTnbTMhW5WG8faOTaYjrWBG8iCGjKiGCIreLDDwcwb0Aib5AQmCRmarv/Qe=4GcDG7kiDD===; tfstk=eDZ9QMmym6fi0XRr-GQ30tayWzWhrleZI5yWmjcMlWFLF8RilVt1MyFbTVc_D--xh-NVQjXN-RyZ0m1lZmIuQRRA5aWhqv2I8MnfZ_jH-pgNsmaGdL3lxJSMiUXyxkqxCaasOLilWPktWjKm9nIlnAgtNRGdN_Zd6Vh7CXKf4qZu2C8MZbHD59BpuEusLJ0ZOATaPYyZpbXH-E8q-vkKZ9BpuEusLvhlKMY2u2DF.; Hm_lpvt_9793f42b498361373512340937deb2a0=1707187956'
})
response.encoding='utf-8'

for i in response.json()['data']:
    print(i['bookName'])

