import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-widget-affiche',
  templateUrl: './widget-affiche.component.html',
  styleUrls: ['./widget-affiche.component.css']
})
export class WidgetAfficheComponent implements OnInit {
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
      name: 'Афиша'
    };
    this.body = {
      items: ['Во всем виноват енот', 'Трансформеры: Последний...',
        'Гадкий я 3', 'Тачки 3', 'Синяя бездна'],
      descriptions: ['премьера завтра', 'фантастика', 'мультфильм',
        'мультфильм', 'ужасы']
    };
  }
}
