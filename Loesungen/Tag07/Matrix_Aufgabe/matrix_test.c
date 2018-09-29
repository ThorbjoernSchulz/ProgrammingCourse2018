#include <stdio.h>
#include <assert.h>
#include "matrix.h"

int fibonacci(int n) {
  if (n == 0) return 0;

  IntMatrix *fib_mat = IntMatrix_new(2, 2);
  if (!fib_mat) return -1;

  /* Fibonacci Matrix: (1 1)
   *                   (1 0)
   */

  IntMatrix_set(fib_mat, 0, 0, 1);
  IntMatrix_set(fib_mat, 1, 0, 1);
  IntMatrix_set(fib_mat, 0, 1, 1);

  IntMatrix *solution_matrix = IntMatrix_power(fib_mat, n-1);
  if (!solution_matrix) {
    IntMatrix_delete(fib_mat);
    return -1;
  }

  int solution = IntMatrix_get(solution_matrix, 0, 0);
  IntMatrix_delete(fib_mat);
  IntMatrix_delete(solution_matrix);

  return solution;
}

void TEST_matrix(void) {
  int fibonacci_numbers[] = {
      0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,
      2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393,
      196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887
  };

  for (int i = 0; i < sizeof(fibonacci_numbers) / sizeof(int); ++i)
    assert(fibonacci_numbers[i] == fibonacci(i));
}

int main(void) {
  TEST_matrix();
  puts("All tests passed.");
  return 0;
}
