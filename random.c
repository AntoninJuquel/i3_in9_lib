#include <stdlib.h>
#include <time.h>
#include "random.h"

static unsigned long seed = 0;

double random_double(double a, double b)
{
    seed++;
    srand(time(NULL) + seed);
    return rand() / (RAND_MAX / (b - a)) + a;
}
float random_float(float a, float b)
{
    return (float)random_double(a, b);
}
size_t random_size_t(size_t a, size_t b)
{
    return (size_t)random_float(a, b);
}
int random_int(int a, int b)
{
    return (int)random_size_t(a, b);
}
unsigned char random_uchar(unsigned char a, unsigned char b)
{
    return (unsigned char)random_int(a, b);
}
void random_init_string(unsigned char *c, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        c[i] = random_uchar('a', 'z');
    }
    
}