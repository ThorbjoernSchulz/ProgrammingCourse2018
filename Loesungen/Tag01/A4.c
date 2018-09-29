#include <stdio.h>

int main(void) {
  int x = 2;

  // My take..
  x *= x * x;
  x *= x * x;
  x *= x * x;

  printf("%i\n", x);
  return 0;
}
