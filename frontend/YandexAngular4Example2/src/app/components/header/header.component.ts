import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.css']
})
export class HeaderComponent implements OnInit {
  location: string;
  account: {
    settings: string,
    mail: string,
    disk: string,
    name: string
  };
  icon: string;

  constructor() { }

  ngOnInit () {
    this.location = 'Одинцово';
    this.account = {
      settings: 'Настройки',
      mail: 'Почта',
      disk: 'Диск',
      name: 'mvshmakov'
    };
    this.icon = 'https://avatars.mds.yandex.net/get-yapic/0/0-0/islands-middle';
  }
}