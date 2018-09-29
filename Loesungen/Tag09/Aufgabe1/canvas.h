#include <stdio.h>

typedef struct Position {
  unsigned x, y;
} Position;

struct CanvasImpl;
typedef struct CanvasImpl* Canvas;

Canvas Canvas_new(unsigned width, unsigned height);

void Canvas_delete(Canvas canvas);

void Canvas_set_pixel(Canvas canvas, Position p, unsigned char grey_value);

void Canvas_draw(Canvas canvas, unsigned (*function)(unsigned, unsigned));

void Canvas_export(Canvas canvas, FILE *file);

