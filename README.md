# gvector
A simple vector implementation in C. 

## API

### `vector * vector_create(size_t capacity, void (*dealloc_fn)(void *))`

### `void vector_set_capacity_increase_factor(vector *v, float capacity_increase_factor)`

### `void vector_push_back(vector *v, void *value)`

### `void vector_insert(vector *v, size_t pos, void *value)`

### `size_t vector_set(vector *v, size_t pos, void *value)`

### `void *vector_get(vector *v, size_t pos)`

### `size_t vector_size(vector *v)`

### `int vector_empty(vector *v)`

### `size_t vector_capacity(vector *v)`

### `void vector_erase(vector *v, size_t pos)`

### `void vector_clear(vector *v)`

### `void vector_destroy(vector **v)`

## Licence
The MIT License (MIT)
Copyright (c) 2015 Gianis Vrentzos <gvre@gvre.gr>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
