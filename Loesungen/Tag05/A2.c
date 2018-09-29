#include "arrayhelpers.h"

/* Hilfsfunktion zum Tauschen zweier ganzzahliger Variablen. */
void int_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void array_print (int *array, int length) {
    int i;
    printf("{");
    for (i=0;i<length;i++) {
        printf("%i",array[i]);
        if (i!=length-1) 
            printf(",");
    }
    printf("}\n");
}

void array_sort(int *array, int length) {
    int i,j;

    /* Wir durchlaufen zunächst mit i das gesamte array: */
    for (i=0;i<length;i++) {
        /* Die Variable index_smallest speichert in diesem Durchlauf
           den Index des kleinsten Elements ab Index i. */
        int index_smallest = i;
        /* Nun durchlaufen wir alle Einträge nach dem Index i und 
           aktualisieren index_smallest, wenn wir einen Eintrag vor-
           finden, welcher kleiner als array[i] ist. */
        for (j=i+1;j<length;j++) {
            if (array[j] < array[index_smallest])
                index_smallest = j;
        }
        /* Wir tauschen den Eintrag beim Index i mit dem Eintrag beim
           Index index_smallest. */
        int_swap(array+i, array+index_smallest);
    }
}

void array_rotate1(int *array, int length) {
    /* Erstelle eine Laufvariable i und merke dir den letzten Eintrag
       des arrays in einer Variable carry. */
    int i, carry = array[length-1];
    /* Wir schreiben jetzt für alle i > 1 den Wert beim Index i in 
       die Variable beim Index i-1. */
    for (i=length-1;i>0;i--)
        array[i] = array[i-1];
    /* Schlussendlich kopieren wir das ehemals letzte Element in den
       Eintrag beim Index 0. */
    array[0] = carry;    
}

void array_rotate(int *array, int length, int k) {
    while (k--) array_rotate1(array,length);
}

void array_reverse(int *array, int length) {
    int i;
    /* Um das array umzudrehen, tauschen wir von außen nach innen
       jeweils die sich "gegenüberliegenden" speicherzellen. Ein
       Beispiel:

       { 5, 9, 7, 2, 8, 3, 1, 0, 7 }  i = 9/2 = 4
       { 7, 9, 7, 2, 8, 3, 1, 0, 5 }  i = 3
       { 7, 0, 7, 2, 8, 3, 1, 9, 5 }  i = 2
       { 7, 0, 1, 2, 8, 3, 7, 9, 5 }  i = 1
       { 7, 0, 1, 3, 8, 2, 7, 9, 5 }  i = 0  */

    for (i=length/2;i>=0;i--)
        int_swap(array+i-1, array+length-i);
}

int array_search(
    int *haystack, 
    int  haystack_length,
    int *needle,
    int  needle_length) {
    
    int i,j;
    
    /* Wenn needle groesser als haystack ist, wird diese
     * Schleife nie betreten. */
    for (i=0;i<haystack_length-needle_length; i++) {
        
        /* Ueberpruefe, ob an dieser Stelle needle auftaucht: */
        for (j=0;j<needle_length;j++)
            if (haystack[i+j] != needle[j])
                break;
        /* wenn die obige Schleife komplett durchlaufen wurde,
         * so steht bei haystack+i das array needle und wir
         * koennen die Position zurueckgeben. */
        
        if (j==needle_length)
            return i;    
    }
    
    return -1; /* nicht gefunden. */
}
