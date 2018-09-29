#include <stdlib.h>
#include <assert.h>
#include "List/list.h"
#include "queue.h"

// Hier die Lösung ...

struct IntQueue {
  IntList list;
};

IntQueue *IntQueue_new(void) {
  struct IntQueue *queue = malloc(sizeof(struct IntQueue));
  if (!queue) return NULL;
  queue->list = IntList_new();
  if (!queue->list) return NULL;
  return queue;
}

int IntQueue_enqueue(IntQueue *queue, int value) {
  assert(queue);
  return IntList_insert(queue->list, ListEnd, value) == NULL;
}

int IntQueue_dequeue(IntQueue *queue) {
  assert(queue);
  IntListPos front = IntList_front(queue->list);
  int value = *front;
  IntList_remove(queue->list, front);
  return value;
}

void IntQueue_delete(IntQueue *queue) {
  if (!queue) return;
  IntList_delete(queue->list);
  free(queue);
}

int IntQueue_empty(IntQueue *queue) {
  assert(queue);
  return IntList_empty(queue->list);
}
