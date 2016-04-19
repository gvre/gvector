#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>

typedef struct vector {
    size_t capacity;
    size_t size;
    float capacity_increase_factor;
    void **items;
    void (*dealloc_fn)(void *it);
} vector;

vector * vector_create(size_t capacity, void (*dealloc_fn)(void *));
void vector_set_capacity_increase_factor(vector *v, float capacity_increase_factor);
void vector_push_back(vector *v, void *value);
void vector_insert(vector *v, size_t pos, void *value);
size_t vector_set(vector *v, size_t pos, void *value);
void *vector_get(vector *v, size_t pos);
size_t vector_size(vector *v);
int vector_empty(vector *v);
size_t vector_capacity(vector *v);
void vector_erase(vector *v, size_t pos);
void vector_clear(vector *v);
void vector_destroy(vector **v);

#endif
