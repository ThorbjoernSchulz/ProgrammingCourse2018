#pragma once

struct IntMatrix {
  unsigned n, m;
  int *values;
};

typedef struct IntMatrix IntMatrix;

IntMatrix *IntMatrix_new(unsigned n, unsigned m);

void IntMatrix_delete(IntMatrix *m);

int IntMatrix_get(IntMatrix *m, int x, int y);

void IntMatrix_set(IntMatrix *m, int x, int y, int v);

IntMatrix *IntMatrix_id(unsigned dim);

void IntMatrix_add(IntMatrix *m1, IntMatrix *m2);

void IntMatrix_scalar_mul(IntMatrix *m1, int lambda);

IntMatrix *IntMatrix_mul(IntMatrix *m1, IntMatrix *m2);

IntMatrix *IntMatrix_power(IntMatrix *m1, int power);

void IntMatrix_print(IntMatrix *m);
