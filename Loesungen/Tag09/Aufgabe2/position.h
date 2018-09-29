#pragma once

typedef struct Position {
  int x;
  int y;
} Position;

bool are_on_diagonal(Position a, Position b);

bool are_on_horizontal(Position a, Position b);

bool collision(Position a, Position b);

