import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';

import {AppComponent} from './app.component';
import { WidgetMapComponent } from './components/widgets/widget-map/widget-map.component';
import { WidgetJamsComponent } from './components/widgets/widget-jams/widget-jams.component';
import { WidgetWeatherComponent } from './components/widgets/widget-weather/widget-weather.component';
import { WidgetPopularComponent } from './components/widgets/widget-popular/widget-popular.component';
import { WidgetTelevisionComponent } from './components/widgets/widget-television/widget-television.component';
import { WidgetAfficheComponent } from './components/widgets/widget-affiche/widget-affiche.component';
import { WidgetsComponent } from './components/widgets/widgets.component';
import { HeaderComponent } from './components/header/header.component';

@NgModule({
  declarations: [
    AppComponent,
    WidgetMapComponent,
    WidgetJamsComponent,
    WidgetWeatherComponent,
    WidgetPopularComponent,
    WidgetTelevisionComponent,
    WidgetAfficheComponent,
    WidgetsComponent,
    HeaderComponent
  ],
  imports: [
    BrowserModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
