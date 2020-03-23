import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcWidgetsComponent } from './nc-widgets.component';

describe('NcWidgetsComponent', () => {
  let component: NcWidgetsComponent;
  let fixture: ComponentFixture<NcWidgetsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcWidgetsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcWidgetsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
