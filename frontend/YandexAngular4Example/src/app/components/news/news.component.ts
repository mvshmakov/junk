import { Component, OnInit } from '@angular/core';
import { Observable } from 'rxjs/Observable'

@Component({
  selector: 'app-news',
  templateUrl: './news.component.html',
  styleUrls: ['./news.component.css']
})
export class NewsComponent implements OnInit {
  header: {
    headers: string[],
    date: string,
    time: string,
  };

  /*body: string[];*/
  body: Observable;

  footer: {
    currency: string[],
    value: string[]
  };

  constructor() { };

  ngOnInit () {
    this.header = {
      headers: ['Главное в СМИ', 'Москва и Московская область'],
      date: '6 июля, четверг',
      time: '14:52'
    };

    /*this.body = ['Кремль прокомментировал поездку Путина на лимузине «Кортеж»',
      'Путин освободил от должности восемь генералов МВД, МЧС и ФСИН',
      'Трамп: Россия дестабилизирует ситуацию в Восточной Европе',
      'Глава Крыма объявил об увольнении трех министров и мэра Ялты',
      'Siemens опровергла сообщения о поставках турбин в Крым в обход санкций'
    ];*/
    this.body = new Observable(observer => {
      setTimeout(() => {
        observer.next()
      }, 1000);
      setTimeout(() => {
        observer.next()
      }, 1000);
      setTimeout(() => {
        observer.complete()
      }, 1000);
    });

    this.footer = {
      currency: ['USD ЦБ', 'EUR ЦБ', 'Нефть'],
      value: ['60,24 +0,66', '68,38 +0,70', '48,50 +0,58%']
    }
  };
}
