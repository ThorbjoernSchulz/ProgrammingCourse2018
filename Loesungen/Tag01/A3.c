#include <stdio.h>

int main(void) {
  int n = 4;

  // Variante 1:
  if (n % 2) // wenn n bei Division mit 2 einen Rest lässt, ist n ungerade
    ++n;

  printf("f(n) = %d\n", n/2);

  // Variante 2:
  // Das konvertieren von einer Fließkommazahl zu einem Integer schneidet
  // die Kommastellen einfach ab.
  printf("f(n) = %d\n", (int)((double)n / 2 + 0.51));

  return 0;
}
