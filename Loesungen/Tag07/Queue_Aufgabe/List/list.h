#pragma once

struct IntListImpl;

typedef struct IntListImpl *IntList;
typedef int *IntListPos;
#define ListEnd (void *)0x10

// returns a new IntList. it needs to be manually freed by IntList_delete
IntList IntList_new(void);

// inserts a new element before IntListPos
// returns the position of the inserted element or NULL if there was an error
IntListPos IntList_insert(IntList, IntListPos, int);

// removes the element at pos
void IntList_remove(IntList, IntListPos pos);

// returns the position of the first node with the specified value,
// returns ListEnd if no such node could be found
IntListPos IntList_find(IntList, int);

// returns the position of the first node;
IntListPos IntList_front(IntList);

// returns the position of the last node just before ListEnd
IntListPos IntList_back(IntList);

// returns next position after pos or ListEnd if at end
IntListPos IntList_next(IntListPos pos);

// returns next position before pos or NULL if at start
IntListPos IntList_prev(IntListPos pos);

// returns 1 if list is empty, 0 otherwise
int IntList_empty(IntList);

// deletes the IntList. accessing the list after deletion results in
// undefined behaviour
void IntList_delete(IntList);
