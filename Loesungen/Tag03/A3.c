#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool odd(int x) {
  return (x % 2) == 1;
}

int half(int a) {
  return a / 2;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                      Aufgabe 3 a                          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Gibt z mal a zurück
int egyptian_multiplication(int z, int a) {
  if (a == 0) return 0;

  int k = 0;

  while (a > 1) {
    if (odd(a)) {
      --a;
      k += z;
    }
    else {
      a = half(a);
      z += z;
    }
  }

  return k + z;
}

// Gibt z hoch a zurück. Wir mussten nur das neutrale Element anpassen und
// die Operation. Klasse, oder?
double power(double z, int a) {
  if (a == 0) return 1;

  double k = 1;

  while (a > 1) {
    if (odd(a)) {
      --a;
      k *= z;
    }
    else {
      a = half(a);
      z *= z;
    }
  }

  return k * z;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                      Aufgabe 3 b                          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

double naiv_power(double x, int n) {
  double solution = 1.0;
  for (int i = 0; i < n; ++i)
    solution *= x;

  return solution;
}

double time_difference(clock_t t1, clock_t t2) {
  return (double)(t2 - t1) / CLOCKS_PER_SEC;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                      Aufgabe 3 b & c                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


int main(void) {
  clock_t t1 = clock();
  double solution1 = naiv_power(0.9999999999, 2000000000);
  clock_t t2 = clock();

  clock_t t3 = clock();
  double solution2 = power(0.9999999999, 2000000000);
  clock_t t4 = clock();

  printf("%lf == %lf\n", solution1, solution2);
  printf("Time for naiv_power:\t%lf seconds\n", time_difference(t1, t2));
  printf("Time for power: \t%lf seconds\n", time_difference(t3, t4));
  return 0;
}
