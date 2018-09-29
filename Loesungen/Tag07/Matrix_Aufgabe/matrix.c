#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "matrix.h"

static IntMatrix *IntMatrix_alloc(unsigned n, unsigned m) {
  IntMatrix *matrix = malloc(sizeof(IntMatrix));
  if (!matrix) return NULL;

  matrix->n = n;
  matrix->m = m;
  matrix->values = malloc(n * m * sizeof(int));
  if (!matrix->values) {
    free(matrix);
    return NULL;
  }

  return matrix;
}

IntMatrix *IntMatrix_new(unsigned n, unsigned m) {
  IntMatrix *matrix = IntMatrix_alloc(n, m);
  if (!matrix) return NULL;
  memset(matrix->values, 0, n * m * sizeof(int));
  return matrix;
}

void IntMatrix_delete(IntMatrix *m) {
  if (!m) return;
  free(m->values);
  free(m);
}

int IntMatrix_get(IntMatrix *m, int x, int y) {
  assert(m);
  return m->values[y * m->m + x];
}

void IntMatrix_set(IntMatrix *m, int x, int y, int v) {
  assert(m);
  m->values[y * m->m + x] = v;
}

IntMatrix *IntMatrix_id(unsigned dim) {
  IntMatrix *matrix = IntMatrix_new(dim, dim);
  if (!matrix) return NULL;

  while (dim--)
    IntMatrix_set(matrix, dim, dim, 1);

  return matrix;
}

void IntMatrix_print(IntMatrix *m) {
  assert(m);
  for (int i = 0; i < m->n; ++i) {
    for (int j = 0; j < m->m; ++j) {
      printf("%d ", IntMatrix_get(m, j, i));
    }
    puts("");
  }
}

void IntMatrix_add(IntMatrix *m1, IntMatrix *m2) {
  assert(m1 && m2);
  size_t size = m1->m * m1->n;
  assert(size == m2->m * m2->n && "Matrices must have equal dimensions");

  while (size--)
    m1->values[size] += m2->values[size];
}

void IntMatrix_scalar_mul(IntMatrix *m1, int lambda) {
  assert(m1);
  size_t size = m1->m * m1->n;

  while (size--)
    m1->values[size] *= lambda;
}

// Wir haben hier die Allokation von dem Rechenteil getrennt,
// daher mul und mul_impl.
static void IntMatrix_mul_impl(IntMatrix *new, IntMatrix *m1, IntMatrix *m2) {
  assert(m1->m == m2->n);
  for (int i = 0; i < new->n; ++i) {
    for (int j = 0; j < new->m; ++j) {
      int sum = 0;
      for (int k = 0; k < m1->m; ++k) {
        sum += IntMatrix_get(m1, k, i) * IntMatrix_get(m2, j, k);
      }
      IntMatrix_set(new, j, i, sum);
    }
  }
}

IntMatrix *IntMatrix_mul(IntMatrix *m1, IntMatrix *m2) {
  assert(m1->m == m2->n);
  IntMatrix *new = IntMatrix_new(m1->n, m2->m);
  if (!new) return NULL;

  IntMatrix_mul_impl(new, m1, m2);

  return new;
}

IntMatrix *IntMatrix_copy(IntMatrix *m) {
  assert(m);
  IntMatrix *copy = IntMatrix_alloc(m->n, m->m);
  if (!copy) return NULL;

  memcpy(copy->values, m->values, m->n * m->m * sizeof(int));
  return copy;
}

static bool odd(int n) { return n % 2 == 1; }

static int half(int n) { return n/2; }

static void swap(IntMatrix **a, IntMatrix **b) {
  IntMatrix *tmp = *a;
  *a = *b;
  *b = tmp;
}

static IntMatrix *IntMatrix_power_acc(int n, IntMatrix *a, IntMatrix *acc) {
  // we want to work on a copy of "a", this ensures we don't break things
  // outside of this function
  a = IntMatrix_copy(a);
  if (!a) return NULL;

  IntMatrix *tmp = IntMatrix_new(a->n, a->m);
  if (!tmp) return NULL;

  // basically egyptian multiplication
  while (true) {
    while (!odd(n)) {
      IntMatrix_mul_impl(tmp, a, a);
      swap(&a, &tmp);
      n = half(n);
    }

    IntMatrix_mul_impl(tmp, acc, a);
    swap(&acc, &tmp);

    if (n == 1) break;

    --n;
  }

  IntMatrix_delete(tmp);
  IntMatrix_delete(a);
  return acc;
}

IntMatrix *IntMatrix_power(IntMatrix *m1, int power) {
  assert(m1 && m1->n == m1->m);
  IntMatrix *id = IntMatrix_id(m1->n);
  if (!id) return NULL;

  if (power == 0) return id;

  return IntMatrix_power_acc(power, m1, id);
}
