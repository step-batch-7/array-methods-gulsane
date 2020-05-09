#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *create_array(int length)
{
  Array *new_array = (Array *)malloc(sizeof(Array));
  new_array->array = (int *)malloc(sizeof(int) * length);
  new_array->length = 0;
  return new_array;
}
