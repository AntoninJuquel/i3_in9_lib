#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "vector.h"

void insert_erase_random(p_s_vector p_vector, size_t n)
{
    printf("Inserting and removing %ld values\n", n);
    for (size_t i = 0; i < n; i++)
    {
        size_t position = random_size_t(0, p_vector->size - 1);
        double value = random_double(-10, 10);
        printf("%ld :  tab[%ld] = %f\n", i, position, value);
        vector_insert(p_vector, position, value);
        vector_erase(p_vector, position);
    }
    
    vector_print(p_vector);
}

int main(int argc, char *argv[])
{
    printf("BENCH VECTOR\n");

    size_t size;
    size_t n;

    if (argc < 3)
    {
        printf("Tab size\n");
        scanf("%ld", &size);
        printf("Tests number\n");
        scanf("%ld", &n);
    }
    else
    {

        size = atoi(argv[1]);
        n = atoi(argv[2]);
    }

    printf("size : %ld\n", size);
    printf("tests : %ld\n", n);

    p_s_vector vector = vector_alloc(size);
    insert_erase_random(vector, n);

    vector_free(vector);

    return 1;
}
