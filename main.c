#include <stdio.h>
#include "array.h"

int mul_by_two(int number)
{
  return number * 2;
}

int main(void)
{
  Array *array = create_array(10);

  for (size_t i = 0; i < array->length; i++)
  {
    array->array[i] = i + 1;
  }

  Array *mapped_array = map(array, &mul_by_two);
  display_array(mapped_array);
}