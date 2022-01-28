#include <stdio.h>
#include "random.h"

int main()
{
    printf("DEBUT DES TEST\n");

    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        printf("%zd\n", random_size_t(0, 145353535555));
    }

    return 0;
}