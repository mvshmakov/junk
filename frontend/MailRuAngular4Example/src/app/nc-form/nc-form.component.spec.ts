import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcFormComponent } from './nc-form.component';

describe('NcFormComponent', () => {
  let component: NcFormComponent;
  let fixture: ComponentFixture<NcFormComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcFormComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcFormComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
