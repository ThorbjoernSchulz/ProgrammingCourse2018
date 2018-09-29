#pragma once

#include <stdio.h>
#include "position.h"

typedef struct Position Position;

struct MazeImpl;
typedef struct MazeImpl *MazePtr;

// Returns a handle to a new maze or NULL if no maze could be created.
// The maze needs to be freed with Maze_delete
MazePtr Maze_new(FILE *file);

// Returns the width of m
unsigned Maze_width(MazePtr m);

// Returns the height of m
unsigned Maze_height(MazePtr m);

// Returns the entry position of m
Position Maze_entry(MazePtr m);

// Returns a pointer to the field of m at position p
char *Maze_tile(MazePtr m, Position p);

// Prints m to stdout.
void Maze_print(MazePtr m);

// Frees the resources allocated to m
void Maze_delete(MazePtr m);
