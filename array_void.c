#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(int length)
{
  ArrayVoid_ptr new_array_void = (ArrayVoid_ptr)malloc(sizeof(ArrayVoid));
  new_array_void->array = length == 0 ? NULL : (Object *)malloc(sizeof(Object) * length);
  new_array_void->length = length;
  return new_array_void;
}

void display_array_void(ArrayVoid_ptr array_void, Displayer displayer)
{
  for (size_t i = 0; i < array_void->length; i++)
  {
    displayer(array_void->array[i]);
  }
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr des = create_array_void(src->length);

  for (size_t i = 0; i < src->length; i++)
  {
    des->array[i] = (*mapper)(src->array[i]);
  }

  return des;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object temp_array[src->length];
  int matched_count = 0;

  for (size_t i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      temp_array[matched_count] = src->array[i];
      matched_count++;
    }
  }

  ArrayVoid_ptr des = create_array_void(matched_count);
  for (size_t i = 0; i < matched_count; i++)
  {
    des->array[i] = temp_array[i];
  }

  return des;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  Object result = init;
  for (size_t i = 0; i < src->length; i++)
  {
    result = (*reducer)(result, src->array[i]);
  }
  return result;
}
