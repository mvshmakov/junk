import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcContentComponent } from './nc-content.component';

describe('NcContentComponent', () => {
  let component: NcContentComponent;
  let fixture: ComponentFixture<NcContentComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcContentComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcContentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
