#include <stdlib.h>
#include "Maze.h"

typedef struct MazeImpl {
  unsigned width, height;
  char *memory;
  Position entry;
} MazeImpl;

MazePtr Maze_new(FILE *file) {
  if (!file) return NULL;
  unsigned width, height;
  if (fscanf(file, "%u %u", &width, &height) != 2) {
    perror("fscanf");
    return NULL;
  }

  MazeImpl *maze = malloc(sizeof(MazeImpl));
  if (!maze)
    return NULL;

  maze->memory = malloc(width * height);
  if (!maze->memory) {
    free(maze);
    return NULL;
  }

  maze->width = width;
  maze->height = height;

  // ok read that maze into the memory
  unsigned end_pos = width * height;
  unsigned current_pos = 0;
  while (current_pos < end_pos) {
    int byte = fgetc(file);

    if (byte == EOF) {
      fputs("ERROR: Are the dimensions of the file correct?", stderr);
      Maze_delete(maze);
      return NULL;
    }

    if (byte == '\n')
      continue;

    if (byte == '*') {
      Position entry = {.x = current_pos % width , .y = current_pos / width};
      maze->entry = entry;
    }

    maze->memory[current_pos] = (char)byte;

    ++current_pos;
  }

  return maze;
}

unsigned Maze_width(MazePtr m) {
  return m->width;
}

unsigned Maze_height(MazePtr m) {
  return m->height;
}

Position Maze_entry(MazePtr m) {
  return m->entry;
}

char *Maze_tile(MazePtr m, Position p) {
  unsigned pos = p.y * m->width + p.x;
  return m->memory + pos;
}

void Maze_print(MazePtr m) {
  unsigned lines = m->height;
  char *pos = m->memory;
  while (lines--) {
    printf("%.*s\n", m->width, pos);
    pos += m->width;
  }
}

void Maze_delete(MazePtr m) {
  if (!m) return;
  free(m->memory);
  free(m);
}
