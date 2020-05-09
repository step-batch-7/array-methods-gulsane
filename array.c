#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *create_array(int length)
{
  Array *new_array = (Array *)malloc(sizeof(Array));
  new_array->array = (int *)malloc(sizeof(int) * length);
  new_array->length = length;
  return new_array;
}

void display_array(Array *array)
{
  for (size_t i = 0; i < array->length; i++)
  {
    printf("%d\n", array->array[i]);
  }
}

Array *map(Array *array, Mapper callback)
{
  Array *new_array = create_array(array->length);

  for (size_t i = 0; i < array->length; i++)
  {
    new_array->array[i] = (*callback)(array->array[i]);
  }

  return new_array;
}