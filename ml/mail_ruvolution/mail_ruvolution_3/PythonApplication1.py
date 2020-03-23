#! /usr/bin/env python
# -*- coding: utf-8 -*-
import requests
import json
import time
import datetime
import nltk
import re
from pymystem3 import Mystem
url = "https://e.mail.ru/api/v1/"
token = "749f312eca3976d786b0c79c73de7119020c5fb537363830"
email = "smartmail_team5@mail.ru"


def req(method='messages/status', par='folders=0'):
    link = url + method + "?access_token=" + token + "&email=" + email + "&" + par
    resp = requests.get(link).text
    return json.loads(resp)

sbj_topic_labels = ["Бонусы", "Детские товары c промокодами", "Мебель", "Средства для ухода", "Баллы на карту",
"Бытовая техника",  "Заказ товара", "Личный кабинет", "Информация", "Доставка по Москве", "Магазины Москвы",
"Промокоды",  "Электроника", "Подтверждение заказа", "Акустика", "Новинки", "Бренды", "Доставка", "Оферта", "Игрушки"]

for i in range(len(sbj_topic_labels)):
    sbj_topic_labels[i] = unicode(sbj_topic_labels[i], encoding='utf-8')

topic_labels = sbj_topic_labels + [unicode("Фоновая тема", encoding='utf-8')]

stop_words = """
а
е
и
ж
м
о
на
не
ни
об
но
он
мне
мои
мож
она
они
оно
мной
много
многочисленное
многочисленная
многочисленные
многочисленный
мною
мой
мог
могут
можно
может
можхо
мор
моя
моё
мочь
над
нее
оба
нам
нем
нами
ними
мимо
немного
одной
одного
менее
однажды
однако
меня
нему
меньше
ней
наверху
него
ниже
мало
надо
один
одиннадцать
одиннадцатый
назад
наиболее
недавно
миллионов
недалеко
между
низко
меля
нельзя
нибудь
непрерывно
наконец
никогда
никуда
нас
наш
нет
нею
неё
них
мира
наша
наше
наши
ничего
начала
нередко
несколько
обычно
опять
около
мы
ну
нх
от
отовсюду
особенно
нужно
очень
отсюда
в
во
вон
вниз
внизу
вокруг
вот
восемнадцать
восемнадцатый
восемь
восьмой
вверх
вам
вами
важное
важная
важные
важный
вдали
везде
ведь
вас
ваш
ваша
ваше
ваши
впрочем
весь
вдруг
вы
все
второй
всем
всеми
времени
время
всему
всего
всегда
всех
всею
всю
вся
всё
всюду
г	год
говорил
говорит
года
году
где
да
ее
за
из
ли
же
им
до
по
ими
под
иногда
довольно
именно
долго
позже
более
должно
пожалуйста
значит
иметь
больше
пока
ему
имя
пор
пора
потом
потому
после
почему
почти
посреди
ей
два
две
двенадцать
двенадцатый
двадцать
двадцатый
двух
его
дел
или
без
день
занят
занята
занято
заняты
действительно
давно
девятнадцать
девятнадцатый
девять
девятый
даже
алло
жизнь
далеко
близко
здесь
дальше
для
лет
зато
даром
первый
перед
затем
зачем
лишь
десять
десятый
ею
её
их
бы
еще
при
был
про
процентов
против
просто
бывает
бывь
если
люди
была
были
было
будем
будет
будете
будешь
прекрасно
буду
будь
будто
будут
ещё
пятнадцать
пятнадцатый
друго
другое
другой
другие
другая
других
есть
пять
быть
лучше
пятый
к
ком
конечно
кому
кого
когда
которой
которого
которая
которые
который
которых
кем
каждое
каждая
каждые
каждый
кажется
как
какой
какая
кто
кроме
куда
кругом
с
у
я
та
те
уж
со
то
том
снова
тому
совсем
того
тогда
тоже
собой
тобой
собою
тобою
сначала
только
уметь
тот
тою
хорошо
хотеть
хочешь
хоть
хотя
свое
свои
твой
своей
своего
своих
свою
твоя
твоё
раз
уже
сам
там
тем
чем
сама
сами
теми
само
рано
самом
самому
самой
самого
семнадцать
семнадцатый
самим
самими
самих
саму
семь
чему
раньше
сейчас
чего
сегодня
себе
тебе
сеаой
человек
разве
теперь
себя
тебя
седьмой
спасибо
слишком
так
такое
такой
такие
также
такая
сих
тех
чаще
четвертый
через
часто
шестой
шестнадцать
шестнадцатый
шесть
четыре
четырнадцать
четырнадцатый
сколько
сказал
сказала
сказать
ту
ты
три
эта
эти
что
это
чтоб
этом
этому
этой
этого
чтобы
этот
стал
туда
этим
этими
рядом
тринадцать
тринадцатый
этих
третий
тут
эту
суть
чуть
тысяч
письмо
скидка
акция
товар
заказ
магазин
сайт
рассылка
адрес
посмотреть
купить
оплата
р
"""
def get_message(method="messages/message", par="id=0"):
    link = url + method + "?access_token=" + token + "&email=" + email + "&" + par
    resp = requests.get(link).text
    return json.loads(resp)

regexp_pattern = '.!?,;:\'\"\/\\'

def get_data(id, message=None):
    m = Mystem()
    if message == None:
        message = get_message(par="id="+id)["body"]
    subject_regexped = " ".join([n for n in re.findall(unicode("[а-яё]+", encoding='utf-8'), message["subject"].lower())if not n in unicode(stop_words, encoding='utf-8')])
    text_regexped =  " ".join([n for n in re.findall(unicode("[а-яё]+", encoding='utf-8'), message["body"]["text"].lower()) if not n in unicode(stop_words, encoding='utf-8')])
    subject = ''.join([n for n in m.lemmatize(subject_regexped) if not n in unicode(stop_words, encoding='utf-8')])
    text = ''.join([n for n in m.lemmatize(text_regexped) if not n in unicode(stop_words, encoding='utf-8')])
    email = message["correspondents"]["from"][0]["email"]
    name = message["correspondents"]["from"][0]["name"]
    message_id = message["id"]
    message_stringified = message_id + ' |text ' + re.sub("\s", " ", subject).strip() + ' ' + re.sub("\s", " ", text).strip() + ' |author ' + email + '\n'
    with open('test.txt', 'w', encoding='utf-8') as f:
        f.write(message_stringified)
    test_batch = artm.BatchVectorizer(data_path='test.txt', target_folder='test-model/batches', data_format='vowpal_wabbit', batch_size=250)
    res = model.transform(batch_vectorizer=test_batch)
    res.index = topic_labels[:]
    for col in list(res):
        res = res.sort_values(col, ascending=False)
        res = res.head(3)
        indexs = res.index
        return {'id': id, 'email':email, 'name': name, 'subject': message["subject"], 'snippet': message["snippet"], 'date':message["date"], 'class1':indexs[0], 'w1':res[col][0], 'class2': indexs[1], 'w2': res[col][1],'class3':indexs[2], 'w3': res[col][2]}

def notification():
    while True:
        now = datetime.datetime.now()
        t = now.toordinal()*86400+now.hour*3600+now.minute*60+now.second

        r = req(par = 'folders=0&last_modified='+str(t))
        while(r['status'] != 200):
            if (datetime.datetime.now().second % 5 == 0):
                r = req(par = 'folders=0&last_modified='+str(t))
            time.sleep(1)
        now = datetime.datetime.now()

        p = r['body']['messages'][0]['id']
        res = get_data(id = p) # to db

        print(res['id'], res['name'], res['email'])
        mailbox = Mailbox( \
            message_id = res['id'], \
            name = res['name'], \
            email = res['email'], \
            subject = res['subject'], \
            snippet = res['snippet'], \
            date = res['date'], \
            w1 = res['w1'], \
            w2 = res['w2'], \
            w3 = res['w3'], \
            class1 = res['class1'], \
            class2 = res['class2'], \
            class3 = res['class3'])
        db.session.add(mailbox)
        db.session.commit()

        time.sleep(3)
