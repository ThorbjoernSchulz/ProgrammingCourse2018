#include "queue.h"
#include <assert.h>
#include <stdio.h>

void TEST_new_queue_is_empty() {
  IntQueue *queue = IntQueue_new();
  assert(IntQueue_empty(queue));
  IntQueue_delete(queue);
}

void TEST_enqueue_dequeue() {
  int value = 0;
  IntQueue *queue = IntQueue_new();
  IntQueue_enqueue(queue, 42);
  IntQueue_enqueue(queue, 13);
  assert(!IntQueue_empty(queue));
  value = IntQueue_dequeue(queue);
  assert(value == 42);
  value = IntQueue_dequeue(queue);
  assert(value == 13);
  assert(IntQueue_empty(queue));
  IntQueue_delete(queue);
}

int main(void) {
  puts("Running tests...");
  TEST_new_queue_is_empty();
  puts("TEST_new_queue_is_empty run successfully.");
  TEST_enqueue_dequeue();
  puts("TEST_enqueue_dequeue run successfully.");
  return 0;
}
