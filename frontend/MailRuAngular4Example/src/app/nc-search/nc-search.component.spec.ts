import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcSearchComponent } from './nc-search.component';

describe('NcSearchComponent', () => {
  let component: NcSearchComponent;
  let fixture: ComponentFixture<NcSearchComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcSearchComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcSearchComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
