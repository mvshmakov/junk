import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { WidgetTelevisionComponent } from './widget-television.component';

describe('WidgetTelevisionComponent', () => {
  let component: WidgetTelevisionComponent;
  let fixture: ComponentFixture<WidgetTelevisionComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ WidgetTelevisionComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(WidgetTelevisionComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
