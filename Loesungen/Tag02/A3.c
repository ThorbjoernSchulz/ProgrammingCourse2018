#include <stdio.h>
#include <stdbool.h>

// mit -lm kompilieren
#include <math.h>

bool is_prime(int c) {
  int n = 2;
  double root = sqrt(c);

  while (n < root) {
    if (c % n == 0) return false;
    ++n;
  }

  return true;
}

int main(void) {
  int i;
 
  i = 20001;
  while (!is_prime(i)) 
    ++i;

  printf("Prime: %d\n", i);

  i = 30001;
  while (!is_prime(i)) 
    ++i;

  printf("Prime: %d\n", i);

  i = 40001;
  while (!is_prime(i)) 
    ++i;

  printf("Prime: %d\n", i);

  return 0;
}
