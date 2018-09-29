#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

/* NOTIZ:
 * Diese Datei sollte zunächst nur als object File herausgegeben werden um
 * Information-Hiding besser zu demonstrieren. Die Studenten werden sehen,
 * dass Sie keinerlei Informationen über die Implementierung der Liste haben.
 */

typedef struct IntNode {
  int value;
  struct IntNode *next;
  struct IntNode *prev;
} IntNode;

struct IntListImpl {
  IntNode *first;
  IntNode *last;
};

IntList IntList_new(void) {
  struct IntListImpl *new_list = malloc(sizeof(struct IntListImpl));
  if (!new_list) return NULL;

  new_list->first = new_list->last = ListEnd;
  return new_list;
}

IntListPos IntList_insert(IntList list, IntListPos pos, int value) {
  assert(list && "list should not be null.");
  assert(pos && "Null is no valid position.");

#ifndef NDEBUG
  if (!list || !pos) return NULL;
#endif

  IntNode *new_node = malloc(sizeof(IntNode));
  if (!new_node) return NULL;

  new_node->next = ListEnd;
  new_node->prev = NULL;
  new_node->value = value;

  // insert after last element
  if ((void *)pos == ListEnd) {

    if (IntList_empty(list))
      list->first = list->last = new_node;

    else {
      new_node->prev = list->last;
      list->last->next = new_node;
      list->last = new_node;
    }

    return (IntListPos)new_node;
  }

  // general case
  IntNode *current_node = (IntNode *)pos;
  if (current_node == list->first)
    list->first = new_node;

  IntNode *the_node_before = current_node->prev;
  if (the_node_before)
    the_node_before->next = new_node;
  new_node->prev = the_node_before;

  new_node->next = current_node;
  return (IntListPos)new_node;
}

void IntList_remove(IntList list, IntListPos pos) {
  assert(list && "list should not be null.");
  assert(list && "Null is no valid position.");
  assert(pos != ListEnd && "End of list can't be removed.");

  IntNode *current_node = (IntNode *)pos;

  if (list->first == list->last)
    list->first = list->last = ListEnd;

  else if (current_node == list->first)
    list->first = current_node->next;

  else if (current_node == list->last)
    list->last = current_node->prev;

  else if (current_node)
    current_node->prev->next = current_node->next;

  free(current_node);
}

IntListPos IntList_find(IntList list, int value) {
  IntListPos it = IntList_front(list);
  while (it != ListEnd) {
    if (*it == value)
      return it;
    it = IntList_next(it);
  }
  return (IntListPos)ListEnd;
}

IntListPos IntList_front(IntList list) {
  return (IntListPos)list->first;
}

IntListPos IntList_back(IntList list) {
  return (IntListPos)list->last;
}

IntListPos IntList_next(IntListPos pos) {
  assert(pos && "Null is no valid position.");
  assert(pos != ListEnd && "End of list has no next position.");
  return (IntListPos) ((IntNode *)pos)->next;
}

IntListPos IntList_prev(IntListPos pos) {
  assert(pos && "Null is no valid position.");
  assert(pos != ListEnd && "End of list has no next position.");
  return (IntListPos) ((IntNode *)pos)->prev;
}

int IntList_empty(IntList list) {
  assert(list && "list should not be null.");
  return list->first == ListEnd;
}

void IntList_delete(IntList list) {
  if (!list) return;

  IntListPos it = IntList_front(list);
  while (it != ListEnd) {
    IntNode *current = (IntNode *)it;
    it = IntList_next(it);
    free(current);
  }
}

