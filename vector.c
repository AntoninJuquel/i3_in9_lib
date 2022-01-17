#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

p_s_vector vector_alloc(size_t n)
{
    p_s_vector vector = malloc(sizeof(s_vector));

    if (vector == NULL)
        return vector;

    vector->tab = malloc(sizeof(double) * n);
    vector->size = n;
    for (size_t i = 0; i < n; i++)
    {
        vector->tab[i] = 0.0;
    }

    if (vector->tab == NULL)
    {
        free(vector);
        vector = NULL;
    }

    return vector;
}

void vector_free(p_s_vector p_vector)
{
    free(p_vector->tab);
    free(p_vector);
}

void vector_print(p_s_vector p_vector)
{
    printf("[");
    if (p_vector->size == 0)
    {
        printf("]\n");
        return;
    }
    for (size_t i = 0; i < p_vector->size - 1; i++)
        printf("%lf, ", p_vector->tab[i]);
    printf("%lf]\n", p_vector->tab[p_vector->size - 1]);
    printf("size : %d\n", p_vector->size);
#if V2
    printf("capacity : %d\n", p_vector->capacity);
#endif
}

void vector_set(p_s_vector p_vector, size_t i, double v)
{
    if (p_vector->size < i)
        return;

    p_vector->tab[i] = v;
}

void vector_insert(p_s_vector p_vector, size_t i, double v)
{
    if (p_vector->size < i)
        return;

    p_vector->size++;
    p_vector->tab = realloc(p_vector->tab, sizeof(double) * p_vector->size);
    for (size_t j = p_vector->size - 1; j > i; j--)
    {
        p_vector->tab[j] = p_vector->tab[j - 1];
    }
    p_vector->tab[i] = v;
}

void vector_erase(p_s_vector p_vector, size_t i)
{
    if (p_vector->size < i)
        return;

    p_vector->size--;
    for (size_t j = i; j < p_vector->size; j++)
    {
        p_vector->tab[j] = p_vector->tab[j + 1];
    }
    p_vector->tab = realloc(p_vector->tab, sizeof(double) * p_vector->size);
}

void vector_push_back(p_s_vector p_vector, double v)
{
    vector_insert(p_vector, p_vector->size - 1, p_vector->tab[p_vector->size - 1]);
    p_vector->tab[p_vector->size - 1] = v;
}

void vector_pop_back(p_s_vector p_vector)
{
    vector_erase(p_vector, p_vector->size - 1);
}

void vector_clear(p_s_vector p_vector)
{
    p_vector->size = 0;
    p_vector->tab = realloc(p_vector->tab, sizeof(double) * p_vector->size);
}

int vector_empty(p_s_vector p_vector)
{
    return p_vector->size == 0 ? 0 : 1;
}

size_t vector_size(p_s_vector p_vector)
{
    return p_vector->size;
}