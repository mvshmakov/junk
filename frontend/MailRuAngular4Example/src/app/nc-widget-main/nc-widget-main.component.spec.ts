import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcWidgetMainComponent } from './nc-widget-main.component';

describe('NcWidgetMainComponent', () => {
  let component: NcWidgetMainComponent;
  let fixture: ComponentFixture<NcWidgetMainComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcWidgetMainComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcWidgetMainComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
