#include <stdio.h>

#define PI 3.14159265359

double basler_problem(void) {
  int k = 1;
  double sum = 0;
  double summand = 1.0;

  while (summand > 10E-17) {
    sum += summand;
    ++k;
    summand = 1.0 / k;
    summand /= k;
    // klar, es ist simpler 1.0 / (k * k) zu schreiben, aber wir büßen 
    // Präzision ein (denn: erst wird alles rechts vom "=" evaluiert,
    // und auch dort gibt es nur eine endliche Anzahl von bits zur
    // repräsentation).
    // Testet ruhig, was passiert, wenn ihr 1.0 / (k * k) schreibt.
  }

  return sum;
}

// Variante: Wir haben schon gesehen, dass Quadratzahlen aus der Addition
// ungerader Zahlen errechnet werden können. Addition ist deutlich schneller
// als Multiplikation - wir können das ausnutzen:
// (Tatsächlich ist die Variante etwa doppelt so effizient!)
double basler_variante(void) {
  // Quadratzahlen werden schnell sehr groß, also brauchen wir einen großen
  // Typen.
  long unsigned current_odd_number = 1;
  long unsigned square_number = 1;

  double sum = 0;
  double summand = 1.0;

  while (summand > 10E-17) {
    sum += summand;
    // neue Quadratzahl berechnen
    current_odd_number += 2;
    square_number += current_odd_number;

    summand = 1.0 / square_number;
  }

  return sum;
}

int main(void) {
  printf("Ergebnis: %lf\n"
         "Variante: %lf\n"
         "Pi^2/6:   %lf\n", basler_problem(), basler_variante(), PI*PI / 6);
  return 0;
}

