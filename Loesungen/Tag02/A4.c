#include <stdio.h>

// Der ggt wie auf Blatt 1 beschrieben
int ggt(int a, int b) {
  // Endlosschleife
  while (1) {
    if (a == 0) return b;
    if (b == 0) return a;

    if (a > b) {
      a -= b;
    } 
    else {
      b -= a;
    }
  }
}

// Variante. Das Vertauschen werden wir später in einer seperaten Funktion 
// schreiben können.
int ggt2(int a, int b) {
  while (b != 0) {
    // vertausche a und b
    int tmp = a;
    a = b;
    b = tmp;

    b %= a;
  }

  return a;
}

int main(void) {
  printf("ggt(8, 12) == %d\n", ggt(8, 12));
  printf("ggt(12, 8) == %d\n", ggt2(12, 8));
  return 0;
}
