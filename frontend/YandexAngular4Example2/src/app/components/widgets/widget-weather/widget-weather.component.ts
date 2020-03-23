import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-widget-weather',
  templateUrl: './widget-weather.component.html',
  styleUrls: ['./widget-weather.component.css']
})
export class WidgetWeatherComponent implements OnInit {
  header: {
    name: string;
    icon: string;
    additional: string;
  };
  body: {
    lines: string[]
  };
  constructor() { }

  ngOnInit() {
    this.header = {
      name: 'Погода',
      icon: null,
      additional: '+18°C',
    };
    this.body = {
      lines: ['Ночь +11, утро +12']
    };
  }
}
