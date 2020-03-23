import { MailRuAngular4ExamplePage } from './app.po';

describe('mail-ru-angular4-example App', () => {
  let page: MailRuAngular4ExamplePage;

  beforeEach(() => {
    page = new MailRuAngular4ExamplePage();
  });

  it('should display welcome message', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('Welcome to app!');
  });
});
