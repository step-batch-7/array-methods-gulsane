#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array_Ptr create_array(int length)
{
  Array_Ptr new_array = (Array_Ptr)malloc(sizeof(Array));
  new_array->array = length == 0 ? NULL : (int *)malloc(sizeof(int) * length);
  new_array->length = length;
  return new_array;
}

void display_array(Array_Ptr array)
{
  for (size_t i = 0; i < array->length; i++)
  {
    printf("%d\n", array->array[i]);
  }
}

Array_Ptr map(Array_Ptr src, Mapper mapper)
{
  Array_Ptr new_array = create_array(src->length);

  for (size_t i = 0; i < src->length; i++)
  {
    new_array->array[i] = (*mapper)(src->array[i]);
  }

  return new_array;
}

Array_Ptr filter(Array_Ptr src, Predicate predicate)
{
  int matched_count = 0;
  int temp_array[src->length];

  for (size_t i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      temp_array[matched_count] = src->array[i];
      matched_count++;
    }
  }

  Array_Ptr new_array = create_array(matched_count);

  for (size_t i = 0; i < matched_count; i++)
  {
    new_array->array[i] = temp_array[i];
  }

  return new_array;
}

int reduce(Array_Ptr src, int init, Reducer reducer)
{
  int result = init;
  for (size_t i = 0; i < src->length; i++)
  {
    result = (*reducer)(result, src->array[i]);
  }
  return result;
}