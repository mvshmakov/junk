import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'nc-footer',
  templateUrl: './nc-footer.component.html',
  styleUrls: ['./nc-footer.component.css']
})
export class NcFooterComponent implements OnInit {

  info: string[];
  callback: string[];

  constructor() { }

  ngOnInit() {

    this.info = ['Mail.Ru', 'О компании', 'Реклама', 'Вакансии'];
    this.callback = ['Сделать стартовой страницей', 'Мобильные приложения',
    'Блог', 'Обратная связь', 'Помощь'];
  }

}
