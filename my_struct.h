#ifndef __MY_STRUCT_H__
#define __MY_STRUCT_H__

typedef struct struct_my_struct
{
    char* txt;
    double num;
} s_my_struct;

typedef s_my_struct *p_s_my_struct;

p_s_my_struct my_struct_alloc();
void my_struct_free(p_s_my_struct p_vector);
void my_struct_randoms_init(p_s_my_struct p_vector);
void my_struct_copy(p_s_my_struct p_dest, p_s_my_struct p_src);
int my_struct_cmp(p_s_my_struct p_vector_a, p_s_my_struct p_vector_b);

#endif