import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcNewsComponent } from './nc-news.component';

describe('NcNewsComponent', () => {
  let component: NcNewsComponent;
  let fixture: ComponentFixture<NcNewsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcNewsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcNewsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
