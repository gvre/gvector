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
void vector_insert(vector *v, void *value);
size_t vector_set(vector *v, size_t idx, void *value);
void *vector_get(vector *v, size_t idx);
size_t vector_size(vector *v);
int vector_empty(vector *v);
size_t vector_capacity(vector *v);
void vector_erase(vector *v, size_t idx);
void vector_clear(vector *v);
void vector_destroy(vector **v);

#endif
