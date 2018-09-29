/*
 * Musterlösung: NDamenProblem.
 * Algorithmisch eine nicht optimale Lösung, aber recht kompakt und intuitiv
 * nachvollziehbar.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "position.h"

#define SUCCESS true
#define FAILURE false

static int usage(const char *prog_name);

// tries to position the queen at the n-th x position, so that it would not
// collide with any of the n queens that are on the field already.
// returns SUCCESS if it succeeds to do so or FAILURE if it wasn't possible
static bool set_nth_queen(int n, Position *queens, int field_height);

static bool collides_with_queens(Position current, int n, Position *queens);

// draws a field with the queens in it
static void print_solution(size_t field_size, const Position *queens);

int main(int argc, char *argv[]) {
  if (argc < 2) return usage(argv[0]);

  int n = atoi(argv[1]);
  if (n < 1) return usage(argv[0]);

  Position *queens = malloc(sizeof(Position) * n);
  memset(queens, 0, sizeof(Position) * n);

  bool success = set_nth_queen(0, queens, n);
  if (!success)
    puts("No solution could be found!");
  else
    print_solution((size_t)n, queens);

  free(queens);
  return 0;
}

static int usage(const char *prog_name) {
  fprintf(stderr, "Usage: %s [NUM_QUEENS > 0]\n", prog_name);
  return 1;
}

static bool set_nth_queen(int n, Position *queens, int field_height) {
  if (n == field_height) return SUCCESS;

  for (int i = 0; i < field_height; ++i) {
    Position current_pos = {n, i};
    if (collides_with_queens(current_pos, n, queens)) continue;

    queens[n] = current_pos;
    bool success = set_nth_queen(n + 1, queens, field_height);
    if (success) return SUCCESS;
  }

  return FAILURE;
}

static bool collides_with_queens(Position current, int n, Position *queens) {
  for (int i = 0; i < n; ++i) {
    if (collision(current, queens[i])) return true;
  }
  return false;
}

bool collision(Position a, Position b) {
  return are_on_diagonal(a, b) || are_on_horizontal(a, b);
}

bool are_on_diagonal(Position a, Position b) {
  return abs(a.x - b.x) == abs(a.y - b.y);
}

bool are_on_horizontal(Position a, Position b) {
  return a.y == b.y;
}

static void print_solution(size_t field_size, const Position *queens) {
  size_t size = field_size * (field_size + 1);
  char *string = malloc(size + 1);
  memset(string, '.', size);

  for (int i = 0; i < field_size; ++i) {
    string[i * (field_size + 1) + field_size] = '\n';

    Position queen = queens[i];
    string[queen.y * (field_size + 1) + queen.x] = 'X';
  }
  string[size] = '\0';

  printf("%s", string);
  free(string);
}

