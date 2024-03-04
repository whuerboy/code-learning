import os
import re
import json
import requests
from lxml import etree


def download_songs(url=None):
    if url is None:
        url = 'https://music.163.com/#/playlist?id=2384642500'

    url = url.replace('/#', '').replace('https', 'http')  # ���ַ�������ȥ�ո��תЭ�鴦��
    # ��������������url�ӿڣ�http://music.163.com/song/media/outer/url?id=2384642500
    out_link = 'http://music.163.com/song/media/outer/url?id='
    # ����ͷ
    headers = {
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36',
        'Referer': 'https://music.163.com/',
        'Host': 'music.163.com'
    }
    # ����ҳ���Դ��
    res = requests.get(url=url, headers=headers).text

    tree = etree.HTML(res)
    # �����б�
    song_list = tree.xpath('//ul[@class="f-hide"]/li/a')
    # ����Ǹ���ҳ��
    artist_name_tree = tree.xpath('//h2[@id="artist-name"]/text()')
    artist_name = str(artist_name_tree[0]) if artist_name_tree else None

    # ����Ǹ赥ҳ�棺
    # song_list_tree = tree.xpath('//*[@id="m-playlist"]/div[1]/div/div/div[2]/div[2]/div/div[1]/table/tbody')
    song_list_name_tree = tree.xpath('//h2[contains(@class,"f-ff2")]/text()')
    song_list_name = str(song_list_name_tree[0]) if song_list_name_tree else None

    # �����������ص��ļ���Ϊ�������ֻ�赥��
    folder = './' + artist_name if artist_name else './' + song_list_name

    if not os.path.exists(folder):
        os.mkdir(folder)

    for i, s in enumerate(song_list):
        href = str(s.xpath('./@href')[0])
        song_id = href.split('=')[-1]
        src = out_link + song_id  # ƴ�ӻ�ȡ������ʵ��src��Դֵ
        title = str(s.xpath('./text()')[0])  # ���ֵ�����
        filename = title + '.mp3'
        filepath = folder + '/' + filename
        print('��ʼ���ص�{}�����֣�{}\n'.format(i + 1, filename))

        try:  # ��������
            # ���ظ��
            # download_lyric(title, song_id)

            data = requests.get(src).content  # ���ֵĶ���������

            with open(filepath, 'wb') as f:
                f.write(data)
        except Exception as e:
            print(e)

    print('{}��ȫ�������Ѿ�������ϣ�'.format(len(song_list)))


def download_lyric(song_name, song_id):
    url = 'http://music.163.com/api/song/lyric?id={}&lv=-1&kv=-1&tv=-1'.format(song_id)
    # ����ͷ
    headers = {
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36',
        'Referer': 'https://music.163.com/',
        'Host': 'music.163.com'
        # 'Origin': 'https://music.163.com'
    }
    # ����ҳ���Դ��
    res = requests.get(url=url, headers=headers).text
    json_obj = json.loads(res)
    lyric = json_obj['lrc']['lyric']
    reg = re.compile(r'\[.*\]')
    lrc_text = re.sub(reg, '', lyric).strip()

    print(song_name, lrc_text)


if __name__ == '__main__':
    # music_list = 'https://music.163.com/#/playlist?id=2384642500' #�����嵥
    music_list = 'https://music.163.com/#/artist?id=8325'  # �������а�
    # music_list = 'https://music.163.com/#/search/m/?order=hot&cat=ȫ��&limit=435&offset=435&s=������' #�����б�
    download_songs(music_list)
