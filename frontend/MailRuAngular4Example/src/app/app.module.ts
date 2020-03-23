import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppComponent } from './app.component';
import { NcHeaderComponent } from './nc-header/nc-header.component';
import { NcFooterComponent } from './nc-footer/nc-footer.component';
import { NcFormComponent } from './nc-form/nc-form.component';
import { NcContentComponent } from './nc-content/nc-content.component';
import { NcProductsComponent } from './nc-products/nc-products.component';
import { NcSearchComponent } from './nc-search/nc-search.component';
import { NcNewsComponent } from './nc-news/nc-news.component';
import { NcWidgetsComponent } from './nc-widgets/nc-widgets.component';
import { NcGamesComponent } from './nc-games/nc-games.component';
import { NcWidgetMainComponent } from './nc-widget-main/nc-widget-main.component';

@NgModule({
  declarations: [
    AppComponent,
    NcHeaderComponent,
    NcFooterComponent,
    NcFormComponent,
    NcContentComponent,
    NcProductsComponent,
    NcSearchComponent,
    NcNewsComponent,
    NcWidgetsComponent,
    NcGamesComponent,
    NcWidgetMainComponent
  ],
  imports: [
    BrowserModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
