import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcHeaderComponent } from './nc-header.component';

describe('NcHeaderComponent', () => {
  let component: NcHeaderComponent;
  let fixture: ComponentFixture<NcHeaderComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcHeaderComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcHeaderComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
