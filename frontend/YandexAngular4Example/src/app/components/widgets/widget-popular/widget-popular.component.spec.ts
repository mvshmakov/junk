import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { WidgetPopularComponent } from './widget-popular.component';

describe('WidgetPopularComponent', () => {
  let component: WidgetPopularComponent;
  let fixture: ComponentFixture<WidgetPopularComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ WidgetPopularComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(WidgetPopularComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
