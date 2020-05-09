#ifndef __ARRAY_H
#define __ARRAY_H
typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;

typedef Array *Array_Ptr;

Array_Ptr map(Array_Ptr src, Mapper mapper);
Array_Ptr filter(Array_Ptr src, Predicate predicate);
int reduce(Array_Ptr src, int init, Reducer reducer);

Array_Ptr create_array(int length);
void display_array(Array_Ptr array);
#endif
