import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.css']
})
export class SearchComponent implements OnInit {
  menu: string[];
  searchButton: string;
  link: string;
  additional: {
    info: string,
    link: string
  };

  constructor() { };

  ngOnInit () {
    this.menu = ['Карты', 'Маркет', 'Новости', 'Переводчик', 'Картинки', 'Видео', 'Музыка', 'еще'];
    this.searchButton = 'Найти';
    this.link = 'https://yastatic.net/www/_/x/Q/xk8YidkhGjIGOrFm_dL5781YA.svg';
    this.additional = {
      info: 'Найдется все, например ',
      link: 'самая большая планета солнечной системы'
    };
  };
}
