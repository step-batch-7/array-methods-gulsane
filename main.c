#include <stdio.h>
#include "array.h"

int mul_by_two(int number)
{
  return number * 2;
}

Bool is_greater_than_ten(int number)
{
  if (number > 10)
  {
    return True;
  }
  return False;
}

int main(void)
{
  Array *array = create_array(10);

  for (size_t i = 0; i < array->length; i++)
  {
    array->array[i] = i + 1;
  }

  Array *mul_of_two = map(array, &mul_by_two);
  printf("multiple of twos:\n");
  display_array(mul_of_two);

  Array *greater_than_ten = filter(mul_of_two, &is_greater_than_ten);
  printf("greater than ten:\n");
  display_array(greater_than_ten);
}