#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
  int size;
  int allocated;
  int *data;
};

struct Vector *init(int allocated);
void reallocate(struct Vector *vector, int newsize);
struct Vector *reserve(int allocated, int size, int data[size]);

int size(struct Vector *vector);
int capacity(struct Vector *vector);
int empty(struct Vector *vector);

void insert(struct Vector *vector, int value, int location);
void push_back(struct Vector *vector, int value);
void remove(struct Vector *vector, int location);

void reverse(struct Vector *vector);

int at(struct Vector *vector, int location);

#endif
