import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'nc-form',
  templateUrl: './nc-form.component.html',
  styleUrls: ['./nc-form.component.css']
})
export class NcFormComponent implements OnInit {

  header: string;
  options: string[];
  enter: string;
  recover: {
    forgotten: string,
    remember: string
  };
  footer: {
    register: string,
    mobile: string
  };

  constructor() { }

  ngOnInit() {

    this.header = 'Почта';
    this.options = ['@mail.ru', '@inbox.ru', '@list.ru', '@bk.ru'];
    this.enter = 'Войти';
    this.recover = {
      forgotten: 'Забыли пароль?',
      remember: 'запомнить'
    };
    this.footer = {
      register: 'Регистрация в почте',
      mobile: 'с мобильными приложениями'
    };
  }

}
