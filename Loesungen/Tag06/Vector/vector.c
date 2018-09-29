#include <assert.h>
#include <stdlib.h>
#include "vector.h"

typedef struct IntVectorImpl {
  size_t capacity;
  size_t size;
  int *memory;
} IntVectorImpl;


IntVector IntVector_new(size_t capacity) {
  IntVectorImpl *vector = malloc(sizeof(IntVectorImpl));
  if (vector == NULL) {
    return NULL;
  }
  int *memory = malloc(capacity * sizeof(int));
  if (memory == NULL) {
    free(vector);
    return NULL;
  }

  vector->capacity = capacity;
  vector->size = 0;
  vector->memory = memory;
  return vector;
}

void IntVector_delete(IntVector vector) {
  free(vector->memory);
  free(vector);
}

int IntVector_push_back(IntVector vector, int value) {
  assert(vector != NULL && "Vector darf nicht NULL sein");

  if (vector->capacity == vector->size) {
    // WICHTIG: Nicht das sizeof(int) vergessen wie ich das in der Vorlesung
    // gemacht habe :P
    int *new_memory = realloc(vector->memory, vector->capacity*2 * sizeof(int));
    if (new_memory == NULL) {
      return 1;
    }

    vector->capacity *= 2;
    vector->memory = new_memory;
  }

  vector->memory[vector->size] = value;
  ++vector->size;
  return 0;
}

int IntVector_get(IntVector vector, size_t index) {
  assert(vector != NULL && "Vector darf nicht NULL sein");
  assert(index < vector->size && "Index ist zu groß");
  return vector->memory[index];
}

void IntVector_set(IntVector vector, size_t index, int value) {
  assert(vector != NULL && "Vector darf nicht NULL sein");
  assert(index < vector->size && "Index ist zu groß");
  vector->memory[index] = value;
}

size_t IntVector_size(IntVector vector) {
  return vector->size;
}























