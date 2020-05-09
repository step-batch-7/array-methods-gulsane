#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

Array *map(Array *array, Mapper callback)
{
  int result;
  int value;
  
  Array *new_array = (Array *)malloc(sizeof(Array));

  for (size_t i = 0; i < array->length; i++)
  {
    value = array[i];
    result = (*callback)(value);
    new_array[i] = result;
  }

  return new_array;
}