#include <stdio.h>

int sum_up_odd_numbers(int n) {
  int i = 0, sum = 0;
  while (i < n) {
    sum += 2*i+1;
    ++i;
  }
  return sum;
}

int main(void) {
  for (int i = 1; i <= 15; ++i) {
    printf("%d ", sum_up_odd_numbers(i));
  }
  putchar('\n');

  // Stellt sich heraus: die Summe der ersten n ungeraden Zahlen ergibt n^2
  // Warum dies so ist, lässt sich leicht illustrieren:
  //
  //                 o   ooo
  //      o   oo     o   ooo
  // o + oo = oo + ooo = ooo usw.
  //

  for (int i = 1; i <= 15; ++i) {
    printf("%d ", i*i);
  }
  putchar('\n');

  return 0;
}

