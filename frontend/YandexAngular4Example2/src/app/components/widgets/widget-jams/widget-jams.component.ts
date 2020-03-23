import {Component, OnInit} from '@angular/core';

@Component({
  selector: 'app-widget-jams',
  templateUrl: './widget-jams.component.html',
  styleUrls: ['./widget-jams.component.css']
})
export class WidgetJamsComponent implements OnInit {
  header: {
    name: string;
    icon: string;
    additional: string;
  };
  body: {
    lines: string[]
  };

  constructor() {
  }

  ngOnInit() {
    this.header = {
      name: 'Пробки',
      icon: 'https://yastatic.net/morda-logo/i/citylogos/yandexn1-logo-ru.png',
      additional: '0 баллов',
    };
    this.body = {
      lines: ['На дорогах свободно']
    };
  }
}
