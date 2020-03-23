import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-footer',
  templateUrl: './footer.component.html',
  styleUrls: ['./footer.component.css']
})
export class FooterComponent implements OnInit {
  footerBlocks: {
    first: string[],
    second: string[],
    third: string[],
    fourth: string[]
  };

  constructor() { };

  ngOnInit () {
    this.footerBlocks = {
      first: [ 'Дзен — персональная лента публикаций',
        'Видео — популярные ролики',
        'ТВ онлайн — эфир любимых каналов',
        'Телепередачи — архив лучших выпусков'
      ],
      second: [ 'Директ',
        'Метрика',
        'Реклама',
        'Касса'
      ],
      third: [ 'Вакансии',
        'Блог',
        'Компания',
        'About'
      ],
      fourth: [ 'Помощь',
        'Обратная связь'
      ]
    };
  };
}
