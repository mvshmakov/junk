import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'nc-header',
  templateUrl: './nc-header.component.html',
  styleUrls: ['./nc-header.component.css']
})
export class NcHeaderComponent implements OnInit {

  logo: string;
  menu: string[];
  account: string[];

  constructor() { }

  ngOnInit() {
    this.logo = 'Mail.Ru';
    this.menu = ['Почта', 'Мой Мир', 'Одноклассники', 'Игры',
      'Знакомства', 'Новости', 'Поиск', 'Все проекты'];
    this.account = ['Регистрация', 'Вход'];
  }

}
