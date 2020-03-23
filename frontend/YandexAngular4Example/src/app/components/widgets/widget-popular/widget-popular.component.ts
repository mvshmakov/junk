import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-widget-popular',
  templateUrl: './widget-popular.component.html',
  styleUrls: ['./widget-popular.component.css']
})
export class WidgetPopularComponent implements OnInit {
  header: {
    name: string;
  };
  body: {
    items: string[],
    descriptions: string[]
  };
  constructor() { }

  ngOnInit() {
    this.header = {
      name: 'Посещаемое'
    };
    this.body = {
      items: ['Маркет', 'Авто.ру', 'Недвижимость', 'Работа', 'ЕГЭ', 'Радио', 'Картинки'],
      descriptions: ['шуруповерты до 5000', 'снижение цен на авто', 'ЖК Варшавское ш. 141',
        'зарплата от 50 000 руб', 'тесты по русскому', 'для любителей шансона', 'космос и планеты']
    };
  }
}
