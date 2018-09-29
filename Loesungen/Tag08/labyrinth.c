#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "Maze/Maze.h"


bool in_range(Position p, MazePtr m) {
  return p.x >= 0 && p.x < Maze_width(m) && p.y >= 0 && p.y < Maze_height(m);
}

bool found_treasure(Position p, MazePtr m) {
  assert(in_range(p, m));
  return *Maze_tile(m, p) == '$';
}

bool can_move(Position p, MazePtr m) {
  if (!in_range(p, m)) return false;
  return *Maze_tile(m, p) == ' ' || *Maze_tile(m, p) == '$';
}

Position up(Position p) {
  p.y -= 1;
  return p;
}

Position left(Position p) {
  p.x -= 1;
  return p;
}

Position down(Position p) {
  p.y += 1;
  return p;
}

Position right(Position p) {
  p.x += 1;
  return p;
}

void mark(Position p, MazePtr m) {
  assert(in_range(p, m));
  *Maze_tile(m, p) = '.';
}

void erase(Position p, MazePtr m) {
  assert(in_range(p, m));
  *Maze_tile(m, p) = ' ';
}

bool solve_maze(Position p, MazePtr m) {

  if (found_treasure(p, m)) return true;

  mark(p, m);

  if (can_move(up(p), m)) {
    if (solve_maze(up(p), m)) return true;
  }

  if (can_move(left(p), m)) {
    if (solve_maze(left(p), m)) return true;
  }

  if (can_move(right(p), m)) {
    if (solve_maze(right(p), m)) return true;
  }

  if (can_move(down(p), m)) {
    if (solve_maze(down(p), m)) return true;
  }

  erase(p, m);
  return false;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s [MAZEFILE]\n", argv[0]);
    return 1;
  }

  FILE *maze_file = fopen(argv[1], "r");
  if (!maze_file) {
    perror("FOPEN");
    return 1;
  }

  MazePtr maze = Maze_new(maze_file);
  fclose(maze_file);
  if (!maze) {
    fputs("FATAL: Could not allocate memory for maze!", stderr);
    return 1;
  }

  if (solve_maze(Maze_entry(maze), maze)) {
    puts("Hurray! Found a treasure!\n");
    Maze_print(maze);
  }
  else {
    puts("Could not find a dime...");
  }

  Maze_delete(maze);
}
