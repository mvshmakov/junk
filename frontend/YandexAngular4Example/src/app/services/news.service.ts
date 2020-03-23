import { Injectable } from '@angular/core';
import { NEWS } from '../data/news.data'
import {Observable} from "rxjs/Observable";

@Injectable()
export class NewsService {

  news: string[];
  newsObservable: Observable;

  constructor() {
    this.news = NEWS;

    this.newsObservable = new Observable(observer => {
      setTimeout(() => {
        observer.next()
      }, 1000);
      setTimeout(() => {
        observer.complete()
      }, 1000);
    });
  }

}
