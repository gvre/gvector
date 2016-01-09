/**
The MIT License (MIT) Copyright (c) 2015 Giannis Vrentzos <gvre@gvre.gr>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#define _POSIX_C_SOURCE 200809L /* strdup */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

int main(void)
{
    vector *v = vector_create(1, free);
    
    vector_insert(v, strdup("v1"));
    vector_insert(v, strdup("v2"));
    vector_insert(v, strdup("v3"));
    vector_insert(v, strdup("v4"));
    vector_insert(v, strdup("v5"));
    assert(vector_size(v) == 5);

    printf("item at pos 0 is %s\n", (char *)vector_get(v, 0));
    printf("item at pos 1 is %s\n", (char *)vector_get(v, 1));
    printf("item at pos 2 is %s\n", (char *)vector_get(v, 2));
    printf("item at pos 3 is %s\n", (char *)vector_get(v, 3));
    printf("item at pos 4 is %s\n", (char *)vector_get(v, 4));

    assert(vector_get(v, 5) == NULL);

    vector_erase(v, 1);
    assert(vector_size(v) == 4);
    
    vector_clear(v); 
    assert(vector_size(v) == 0);
    assert(vector_empty(v));

    vector_insert(v, strdup("v10"));
    printf("item at pos 0 is %s\n", (char *)vector_get(v, 0));
    assert(vector_size(v) == 1);

    vector_destroy(&v);
    assert(v == NULL);

    return 0;
}

