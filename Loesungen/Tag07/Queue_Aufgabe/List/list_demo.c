#include <stdio.h>
#include <assert.h>
#include "list.h"

int main(void) {
  IntList list = IntList_new();
  assert(list);

  // Elemente in die Liste einfügen
  for (int i = 0; i < 10; ++i)
    IntList_insert(list, ListEnd, i);

  // Über die Liste iterieren mit einer for-Schleife
  for (IntListPos i = IntList_front(list); i != ListEnd; i = IntList_next(i)) {
    printf("%d ", *i);
  }
  putchar('\n');

  // Rückwärts über die Liste iterieren mit einer while-Schleife
  IntListPos it = IntList_back(list);
  while (it != NULL) {
    printf("%d ", *it);
    it = IntList_prev(it);
  }
  putchar('\n');

  // Elemente löschen
  for (int i = 15; i--;) {
    IntListPos pos = IntList_find(list, i);
    // Die Elemente 14-10 sind nicht in der Liste.
    if (pos != ListEnd)
      IntList_remove(list, pos);
  }

  printf("Empty: %d\n", IntList_empty(list));
  
  IntList_delete(list);
  return 0;
}
