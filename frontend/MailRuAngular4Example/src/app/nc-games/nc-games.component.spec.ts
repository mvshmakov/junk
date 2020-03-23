import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { NcGamesComponent } from './nc-games.component';

describe('NcGamesComponent', () => {
  let component: NcGamesComponent;
  let fixture: ComponentFixture<NcGamesComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ NcGamesComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(NcGamesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should be created', () => {
    expect(component).toBeTruthy();
  });
});
