import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-widget-map',
  templateUrl: './widget-map.component.html',
  styleUrls: ['./widget-map.component.css']
})
export class WidgetMapComponent implements OnInit {
  header: {
    name: string,
    icon: string,
    additional: string
  };
  body: {
    items: string[]
  };
  constructor() { }

  ngOnInit() {
    this.header = {
      name: 'Карта Москвы',
      icon: null,
      additional: null
    };
    this.body = {
      items: ['Метро', 'Такси', 'Расписания', 'Междугородние автобусы']
    };
  }
}
