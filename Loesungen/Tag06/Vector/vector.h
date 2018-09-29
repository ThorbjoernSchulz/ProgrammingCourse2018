




#pragma once

struct IntVectorImpl;
typedef struct IntVectorImpl *IntVector;

IntVector IntVector_new(size_t capacity);

void IntVector_delete(IntVector vector);

int IntVector_push_back(IntVector vector, int val);

int IntVector_get(IntVector vector, size_t index);

void IntVector_set(IntVector vector, size_t index, int value);

size_t IntVector_size(IntVector vector);
