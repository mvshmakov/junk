import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { WidgetJamsComponent } from './widget-jams.component';

describe('WidgetJamsComponent', () => {
  let component: WidgetJamsComponent;
  let fixture: ComponentFixture<WidgetJamsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ WidgetJamsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(WidgetJamsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
