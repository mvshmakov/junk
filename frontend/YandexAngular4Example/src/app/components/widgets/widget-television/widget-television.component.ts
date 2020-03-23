import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-widget-television',
  templateUrl: './widget-television.component.html',
  styleUrls: ['./widget-television.component.css']
})
export class WidgetTelevisionComponent implements OnInit {
  header: {
    name: string;
    icon: string;
    additional: string;
  };
  body: {
    times: string[],
    items: string[],
    descriptions: string[]
  };
  constructor() { }

  ngOnInit() {
    this.header = {
      name: 'Телепрограмма',
      icon: null,
      additional: null,
    };
    this.body = {
      times: ['16:20', '17:00', '18:10', '19:00', '19:30', '20:10'],
      items: ['Мужское / Женское', 'Сегодня', '10 самых.', 'Гадалка', 'Реальные пацаны', 'Информационная программа'],
      descriptions: ['Первый', 'НТВ', 'ТВ Центр', 'ТВ-3', 'ТНТ', 'РЕН ТВ']
    };
  }
}
