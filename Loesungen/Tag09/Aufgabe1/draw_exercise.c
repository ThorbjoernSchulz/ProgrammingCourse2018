#include <stdio.h>
#include "canvas.h"

unsigned example_function(unsigned x, unsigned y) {
  return x ^ y;
}

int main(void) {
  FILE *f = fopen("out.ppm", "w");
  if (!f) {
    perror("out.ppm");
    return 1;
  }

  Canvas canvas = Canvas_new(500, 500);
  Canvas_draw(canvas, example_function);
  Canvas_export(canvas, f);
  Canvas_delete(canvas);

  fclose(f);
}
