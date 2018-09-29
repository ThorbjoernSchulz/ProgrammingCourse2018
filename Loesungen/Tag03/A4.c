#include <stdio.h>

#define PRECISION 1e-17

/* Die folgende Logarithmus-Funktion berechnet den Logarithmus einfach 
   anhand der auf dem Zettel angegebenen Reihe. Leider ist dies für
   extreme Werte nicht schnell genug, siehe dazu den Logarithmus weiter
   unten. */
double _logarithm(double x) {
    unsigned long k;
    double summand = (x - 1) / ( x + 1),
           multiplier = summand * summand;
    double summe = 0;

    /* In jedem Schleifendurchlauf addieren wir den derzeitigen
       Summanden, dividiert durch k, auf die Summe. Wir setzen
       k initial auf 1 und erhöhen jedes mal um 2, dadurch erhalten
       wir den erwünschten Faktor 1/(2k+1) pro summand. 
       Anschließend errechnen wir aus dem derzeitigen Summanden
       den für den nächsten Schleifendurchlauf: Da der multiplier
       das quadrat von (x-1)/(x+1) ist und wir mit (x-1)/(x+1) 
       angefangen haben, erhalten wir auch hier die gewünschte
       Potenz. Das ganze brechen wir ab, sobald (summand/k) zu
       klein wird, als dass es bei unserer präzision noch eine
       Rolle spielen würde, weitere Terme zu addieren. */
    for (k = 1; summand / k > PRECISION; k += 2) {
        summe += summand/k;
        summand *= multiplier; 
    }
    return 2 * summe;
}


double expo(double x) {
    unsigned long k;
    double summe = 0, summand = 1;

    /* Das gleiche Prinzip wie oben in der Logarithmusfunktion.
       Hier ist das Vorgehen, einen Summanden aus dem vorherigen
       zu berechnen, besonders wichtig: Die Fakultät und die 
       Potenz von x einzeln zu berechnen und dann durcheinander
       zu teilen würde schnell zu derart gigantischen Zahlen
       führen, dass der Computer diese nicht mehr genau genug
       handhaben kann. */
    for (k = 1; summand > PRECISION || summand < -PRECISION; k++) {
        summe += summand;
        summand *= x / k;
    }
    return summe;
}

/* Unglücklicherweise konvergiert die Reihe der _logarithm - Funktion 
   nur schnell, wenn x nahe bei 1 ist (sorry). Daher verwenden wir
   einen kleinen Trick: Wir berechnen _logarithm erst für eine schlechte
   Präzision und erhalten damit eine Approximation z von log(x). 
   Wir berechnen dann den Wert
   
            x
     a := ------
          exp(z)
          
   welcher näher bei 1 ist, je besser die Approximation ist. Danach 
   berechnen wir mit leicht verbesserter Präzision den Wert 
   
     z + log(a) = z + log(x) - log(exp(z)) = log(x)
     
   Wenn a nahe 1 ist, können wir frühzeitig abbrechen. */
double logarithm(double x) {
    if (x < 1)  {
        return -logarithm(1/x);
    } else {
        double z=0;
        for (;;) {
            double a = x / expo(z);
            
            /* Wir berechnen den logarithmus von a wie oben */
            double log_a, summand = (a-1)/(a+1),
                multiplier = summand * summand;        
            unsigned long k;
            for (log_a=0,k=1; k < 100; k+=2) {
                log_a   += summand/k;
                summand *= multiplier; 
            }
            log_a *= 2;
            
            /* Falls der Logarithmus von a nahe 0 ist, so war x = exp(z),
               also z der gesuchte Wert. wir brechen ab. Andernfalls wird
               z + log(a) unser neuer, approximativer Wert für log(x). */
            if ( log_a < PRECISION ) 
                break;
            else z += log_a;
        }
        return z;
    }
}

double power(double x, double r) {
    return expo(r * logarithm(x));
}


int main() {
    double a = 0.9999999999;
    unsigned n = 2000000000;
    
    printf("\nTesting power function with floating point exponents:\n");
    printf("%f\n", power(2,0.5));
    printf("%f\n", power(a,n));
    printf("%f\n", power(power(9,100),1./100));
    
    return 0;
}
