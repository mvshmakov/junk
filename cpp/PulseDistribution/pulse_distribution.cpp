#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

float const PI = 3.14159265359;
float func(float f, float fn, float c1, float c2);

struct impulse {
  float f0, dt;
};

int main() {
  int N, Nc;
  float f, fv, fn, L, c1, c2, t, NT, Nt, e0;

  cout << "Enter fn: ";
  cin >> fn;
  cout << "Enter fv: ";
  cin >> fv;
  cout << "Enter L: ";
  cin >> L;
  cout << "Enter N: ";
  cin >> N;
  cout << "Enter Nc: ";
  cin >> Nc;

  float *V = new float[Nc + 1];
  float *U = new float[Nc];
  float *dV = new float[Nc + 1];
  float *dU = new float[Nc];

  f = fn;
  c2 = 1 / ((2 * PI * fn) * (2 * PI * fn) * L);
  cout << c2 << " ";
  c1 = 2 * c2 / ((fv / fn) * (fv / fn) - 1);
  cout << c2 << " ";

  ofstream fout("deviation.txt");
  float **ptrarray = new float *[2];
  for (int count = 0; count < 2; count++)
    ptrarray[count] = new float[N];

  for (int i = 0; f < fv; f += (fv - fn) / (N - 1), i++) {
    ptrarray[1][i] = f;
    fout << ptrarray[1][i] << " ";
    ptrarray[0][i] = func(f, fn, c1, c2);
    fout << ptrarray[0][i] << " " << endl;
  }

  impulse impulse1;
  impulse1.dt = 1 / (fv * Nt);

  for (int i = 0; i < NT; i++) {
    t += impulse1.dt;
    e0 = 2 * sin(2 * PI * impulse1.f0 * t);
  }

  fout.close();

  for (int count = 0; count < 2; count++) {
    delete[] ptrarray[count];
  }

  delete[] V;
  delete[] U;
  delete[] dV;
  delete[] dU;

  return 0;
};

float func(float f, float fn, float c1, float c2) {
  return 2 * asin(sqrt(fabs((1 - (f / fn) * (f / fn)) * c1 / (2 * c2))));
};
