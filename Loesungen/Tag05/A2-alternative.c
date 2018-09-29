#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// a)

void intarray_print(int *array, size_t size, const char *sep, const char *end) {
  if (!array || size < 1) return;

  for (size_t i = 0; i < size - 1; ++i) {
    printf("%d%s", array[i], sep);
  }
  printf("%d%s", array[size - 1], end);
}

void intarray_pretty_print(int *array, size_t size) {
  intarray_print(array, size, ", ", "\n");
}

// b) 

void intarray_set(int *array, size_t size, int value) {
  if (!array || size < 1) return;

  for (size_t i = 0; i < size; ++i) {
    array[i] = value;
  }
}

// c)

void intarray_rotate1(int *array, size_t size) {
  if (!array || size < 1) return;

  int tmp = array[0];
  for (size_t i = 0; i < size - 1; ++i) {
    array[i] = array[i + 1];
  }
  array[size-1] = tmp;
}

// d)

void intarray_rotate_easy_version(int *array, size_t size, int k) {
  if (!array || size < 1) return;

  if (k == 0) return;

  // in die entgegengesetzte Richtung rotieren, einfach positives k
  // berechnen
  if (k < 0)
    k = size - k;

  if (k > size)
    k %= size;

  // einfach mit rotate1 implementieren. Ineffizient aber ist korrekt.
  // Das k-- sorgt dafür, dass k ausgewertet wird für das while,
  // das Dekrementieren aber erst danach passiert.
  // Ihr könnt euch das ja mal für ein konkretes k ausrechnen,
  // aber im Endeffekt wird die Schleife so genau k mal ausgeführt.
  while (k--)
    intarray_rotate1(array, size);
}

void intarray_copy(int *to, int *from, size_t size) {
  int *last = to + size;
  while (to != last)
    *to++ = *from++;
}

// Effizienterer Rotationsalgorithmus, nutzt ein Hilfsarray.
// Es geht noch effizienter, allerdings bräuchte man dann
// zum Verständnis etwas wissen über Permuationen, und daran
// wollen wir uns nicht aufhalten.
void intarray_rotate(int *array, size_t size, int k) {
  if (!array || size < 1) return;

  if (k == 0) return;

  if (k < 0)
    k = size - k;

  if (k > size)
    k %= size;

  // In dem Fall wäre rotate1 schneller
  if (k == 1) {
    intarray_rotate1(array, size);
    return;
  }
  // Die Idee ist: Teile das Array in zwei Bereiche,
  // Einmal vom Anfang bis dorthin, wo das erste Element nach der Rotation
  // landet. Und einmal von dort bis zum Ende.
  // Kopiere diese Bereiche in umgekehrter Reihenfolge in das Hilfsarray,
  // und kopiere dann das Hilfsarray in unser Array (setze die beiden also 
  // gleich).
  // Insgesammt haben wir dann eine Laufzeit in O(2n). Eigentlich ganz
  // in Ordnung.
  int buffer[size];
  size_t rotation_end = size - k;
  for (size_t i = 0; i < rotation_end; ++i)
    buffer[i] = array[i + k];

  for (size_t i = 0; i < k; ++i)
    buffer[rotation_end + i] = array[i]; 

  intarray_copy(array, buffer, size);
}

// e)

void int_swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void intarray_reverse(int *array, size_t size) {
  // Wir arbeiten der Anschaulichkeit halber mal mit Pointern
  int *begin = array;
  int *middle = array + size / 2;
  int *end = array + size - 1;

  // Dieses Beispiel veranschaulicht warum Pointer heißen, wie sie heißen.
  // Es ist als ob "Zeiger" über das Array wandern
  while (begin != middle) {
    int_swap(begin, end);
    ++begin;
    --end;
  }
}

// f)

bool intarray_equal(int *array1, size_t size, int *array2) {
  while (size--)
    if (*array1++ != *array2++) 
      return false;
  return true;
}

ssize_t intarray_find_subarray(int *array, size_t size1, int *subarray, size_t size2) {
  ssize_t difference = size1 - size2;
  if (difference < 0) return -1;

  // Wie oft kann ich das Subarray nach links verschieben?
  size_t max_tries = difference + 1;
  
  for (int i = 0; i < max_tries; ++i) {
    int *p = array + i;
    if (intarray_equal(subarray, size2, p))
      return i;
  }

  return -1;
}

int main(void) {
  int array[10] = { 0 };
  intarray_set(array, 10, 5);
  intarray_pretty_print(array, 10);

  int prime_numbers[] = { 2, 3, 5, 7, 11, 13 };
  size_t pn_size = sizeof(prime_numbers) / sizeof(int);

  intarray_rotate1(prime_numbers, pn_size);
  intarray_pretty_print(prime_numbers, pn_size);

  intarray_rotate_easy_version(prime_numbers, pn_size, 3+pn_size);
  intarray_pretty_print(prime_numbers, pn_size);

  intarray_rotate(prime_numbers, pn_size, -3);
  intarray_pretty_print(prime_numbers, pn_size);

  intarray_reverse(prime_numbers, pn_size);
  intarray_pretty_print(prime_numbers, pn_size);

  int subrange[] = {11, 7, 5};
  printf("subrange in prime_numbers at pos: %li\n",
      intarray_find_subarray(prime_numbers, pn_size, subrange, 3));

  return 0;
}
