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

Array *map(Array *src, Mapper callback)
{
  Array *new_array = create_array(src->length);

  for (size_t i = 0; i < src->length; i++)
  {
    new_array->array[i] = (*callback)(src->array[i]);
  }

  return new_array;
}

Array *filter(Array *src, Predicate callback)
{
  int matched_count = 0;
  int temp_array[src->length];

  for (size_t i = 0; i < src->length; i++)
  {
    if ((*callback)(src->array[i]))
    {
      temp_array[matched_count] = src->array[i];
      matched_count++;
    }
  }

  Array *new_array = create_array(matched_count);

  for (size_t i = 0; i < matched_count; i++)
  {
    new_array->array[i] = temp_array[i];
  }

  return new_array;
}