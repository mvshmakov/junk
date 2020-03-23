import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcFooterComponent } from './nc-footer.component';

describe('NcFooterComponent', () => {
  let component: NcFooterComponent;
  let fixture: ComponentFixture<NcFooterComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcFooterComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcFooterComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
