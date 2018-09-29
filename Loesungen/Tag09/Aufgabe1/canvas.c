#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "canvas.h"

typedef struct CanvasImpl {
  unsigned width, height;
  unsigned char *pixel;
} CanvasImpl;

struct CanvasImpl;
typedef struct CanvasImpl* Canvas;

Canvas Canvas_new(unsigned width, unsigned height) {
  Canvas canvas = calloc(sizeof(CanvasImpl), 1);

  if (!canvas) return NULL;

  canvas->pixel = malloc(width * height);
  if (!canvas->pixel) {
    free(canvas);
    return NULL;
  }

  memset(canvas->pixel, 0, width * height);

  canvas->width = width;
  canvas->height = height;
  return canvas;
}

void Canvas_delete(Canvas canvas) {
  assert(canvas);
  free(canvas->pixel);
  free(canvas);
}

void Canvas_set_pixel(Canvas canvas, Position p, unsigned char grey_value) {
  assert(canvas);
  size_t index = p.y * canvas->width + p.x;
  assert(index < canvas->width * canvas->height);
  canvas->pixel[index] = grey_value;
}

void Canvas_draw(Canvas canvas, unsigned (*function)(unsigned, unsigned)) {
  for (unsigned y = 0; y < canvas->height; ++y) {
    for (unsigned x = 0; x < canvas->width; ++x) {
      Position p = {x, y};
      unsigned char grey_value = (unsigned char)(function(x, y) % 255);
      Canvas_set_pixel(canvas, p, grey_value);
    }
  }
}

void Canvas_export(Canvas canvas, FILE *file) {
  assert(canvas && file);
  /* write header to file */
  fprintf(file, "P2 %u %u 255\n", canvas->width, canvas->height);

  /* write pixel data */
  size_t canvas_size = canvas->height * canvas->width;
  for (size_t i = 0; i < canvas_size; ++i) {
    fprintf(file, "%u\n", canvas->pixel[i]);
  }
}

