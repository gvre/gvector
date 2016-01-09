/**
The MIT License (MIT) Copyright (c) 2015 Giannis Vrentzos <gvre@gvre.gr>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "vector.h"

static void increase_capacity(vector *v);

static void increase_capacity(vector *v)
{
    assert(v != NULL);

    void **old_items = v->items;
    size_t new_capacity = ceil(v->capacity_increase_factor * v->capacity);
    v->items = realloc(v->items, new_capacity * sizeof *v->items);
    if (v->items == NULL) {
        v->items = old_items;
        perror("Could not reallocate memory");
        return;
    } 

    v->capacity = new_capacity;
}

vector * vector_create(size_t capacity, void (*dealloc_fn)(void *it))
{
    vector *v = malloc(sizeof *v);
    if (v == NULL) {
        perror("Could not allocate memory");
        return NULL;
    }

    v->capacity = capacity;
    v->size = 0;
    v->capacity_increase_factor = 1.5;
    v->items = malloc(capacity * sizeof *v->items);
    v->dealloc_fn = dealloc_fn;

    return v;
}

void vector_set_capacity_increase_factor(vector *v, float capacity_increase_factor)
{
    assert(v != NULL);

    if (capacity_increase_factor > 1)
        v->capacity_increase_factor = capacity_increase_factor;
}

void vector_insert(vector *v, void *value)
{
    assert(v != NULL);

    if (v->size == v->capacity)
        increase_capacity(v);
    v->items[v->size++] = value;
}

size_t vector_set(vector *v, size_t idx, void *value)
{
    assert(v != NULL);

    if (idx >= v->size)
        return 0;

    v->items[idx] = value;
    return 1;
}

void *vector_get(vector *v, size_t idx)
{
    assert(v != NULL);

    if (idx >= v->size)
        return NULL;
    return v->items[idx];
}

size_t vector_size(vector *v)
{
    assert(v != NULL);

    return v->size;
}

int vector_empty(vector *v)
{
    assert(v != NULL);

    return v->size == 0;
}

size_t vector_capacity(vector *v)
{
    assert(v != NULL);

    return v->capacity;
}

void vector_erase(vector *v, size_t idx)
{
    assert(v != NULL);

    if (idx >= v->size)
        return;

    if (v->dealloc_fn != NULL) {
        v->dealloc_fn(v->items[idx]);
        v->size--;

        for (size_t i = idx; i < v->size; i++)
            v->items[i] = v->items[i + 1];
    }
}

void vector_clear(vector *v)
{
    assert(v != NULL);

    if (v->dealloc_fn != NULL) {
        for (size_t i = 0; i < v->size; i++)
            v->dealloc_fn(v->items[i]);
    } else {
        for (size_t i = 0; i < v->size; i++)
            v->items[i] = NULL;
    }
    v->size = 0;
}

void vector_destroy(vector **v)
{
    vector_clear(*v);

    free((*v)->items);
    (*v)->items = NULL;

    free(*v);
    *v = NULL;
}

