import { YandexAngular4ExamplePage } from './app.po';

describe('yandex-angular4-example App', () => {
  let page: YandexAngular4ExamplePage;

  beforeEach(() => {
    page = new YandexAngular4ExamplePage();
  });

  it('should display welcome message', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('Welcome to app!');
  });
});
