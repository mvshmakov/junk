import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { WidgetAfficheComponent } from './widget-affiche.component';

describe('WidgetAfficheComponent', () => {
  let component: WidgetAfficheComponent;
  let fixture: ComponentFixture<WidgetAfficheComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ WidgetAfficheComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(WidgetAfficheComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
