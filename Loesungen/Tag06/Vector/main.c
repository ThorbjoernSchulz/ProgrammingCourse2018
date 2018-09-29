#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void error(const char *fname) {
  perror(fname);
  exit(1);
}

int main(void) {
  // erstelle neuen Vector
  IntVector v = IntVector_new(2);
  if (v == NULL)
    error("IntVector_new");

  // Füge die Zahlen von 0 bis 9 hinzu
  for (int i = 0; i < 10; ++i) {
    if (IntVector_push_back(v, i) != 0) 
      error("IntVector_push_back");
  }

  // Gebe Elemente in umgekehrte Reihenfolge aus
  putchar('(');
  size_t i = IntVector_size(v);
  while (i--) {
    printf("%d ", IntVector_get(v, i));
  }
  puts(")");

  // gebe den Vector frei
  IntVector_delete(v);
  return 0;
}
