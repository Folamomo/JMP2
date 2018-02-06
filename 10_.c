#include <stdio.h>
#include <stdlib.h>

struct Vector {
  int size;
  int allocated;
  int *data;
};

struct Vector *init(int allocated) {
  struct Vector *new = (struct Vector *)malloc(sizeof(struct Vector));
  new->size = 0;
  new->allocated = allocated;
  new->data = (int *)malloc(sizeof(int) * allocated);
  if (new->data == NULL) {
    fprintf(stderr, "Not enough memory");
    return NULL;
  }
  return new;
}

void reallocate(struct Vector *vector, int newsize) {
  if (vector->size > newsize) {
    fprintf(stderr, "Warning: Allocated memory is smaller than data size. Some "
                    "data may be lost");
  }
  if (realloc(vector->data, sizeof(int) * newsize) == NULL) {
    fprintf(stderr, "Not enough memory");
    return;
  }
  vector->allocated = newsize;
}

struct Vector *reserve(int allocated, int size, int data[size]) {
  if (allocated < size) {
    fprintf(stderr, "Allocated memory is smaller than data size");
    return NULL;
  }
  struct Vector *vect = init(allocated);
  vect->size = size;
  for (int i = 0; i < size; i++) {
    vect->data[i] = data[i];
  }
  return vect;
}

int size(struct Vector *vector) { return vector->size; }

int capacity(struct Vector *vector) { return vector->allocated; }

int empty(struct Vector *vector) { return vector->size == 0; }

void insert(struct Vector *vector, int value, int location) {
  if (location >= vector->allocated) {
    fprintf(stderr, "Location outside of allocated memory");
    return;
  }
  if (location > vector->size) {
    fprintf(stderr, "Location out of range");
    return;
  }
  for (int i = vector->size; i > location; i--)
    vector->data[i] = vector->data[i - 1];
  vector->data[location] = value;
  vector->size++;
}

void push_back(struct Vector *vector, int value) {
  if (vector->allocated == vector->size) {
    fprintf(stderr, "No free space to add another element");
    return;
  }
  vector->data[vector->size] = value;
  vector->size++;
}

void remove(struct Vector *vector, int location) {
  if (location >= vector->size) {
    fprintf(stderr, "out of range");
    return;
  }
  vector->size--;
  for (int i = location; i < vector->size; i++)
    vector->data[i] = vector->data[i + 1];
  vector->data[vector->size] = 0;
}

void reverse(struct Vector *vector) {
  for (int i = 0; i < vector->size / 2; i++) {
    int tmp = vector->data[i];
    vector->data[i] = vector->data[vector->size - i - 1];
    vector->data[vector->size - i] = tmp;
  }
}

int at(struct Vector *vector, int location) {
  if (location >= vector->size) {
    fprintf(stderr, "Location out of range");
  }
  return vector->data[location];
}
