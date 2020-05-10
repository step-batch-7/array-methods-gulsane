#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "array_void.h"

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

int sum(int num1, int num2)
{
  return num1 + num2;
}

void perform_array_methods(void)
{
  printf("\nPerforming array methods...\n");
  Array_Ptr array = create_array(10);

  for (size_t i = 0; i < array->length; i++)
  {
    array->array[i] = i + 1;
  }

  Array_Ptr mul_of_two = map(array, &mul_by_two);
  printf("multiple of twos:\n");
  display_array(mul_of_two);

  Array_Ptr greater_than_ten = filter(mul_of_two, &is_greater_than_ten);
  printf("greater than ten:\n");
  display_array(greater_than_ten);

  int sum_of_numbers = reduce(array, 0, &sum);
  printf("sum of numbers in list: %d\n", sum_of_numbers);
  printf("Array methods finished...\n");
}

void display_number(Object alphabet)
{
  printf("%d\n", *(int *)alphabet);
}

Object give_double_of(Object number)
{
  int *memory = (int *)malloc(sizeof(int));
  *memory = *(int *)number * 2;
  return (Object)memory;
}

void perform_array_void_methods(void)
{
  printf("\nPerforming array void methods...\n");
  ArrayVoid_ptr numbers = create_array_void(10);
  int *a;
  for (size_t i = 0; i < numbers->length; i++)
  {
    a = malloc(sizeof(int));
    *a = i + 1;
    numbers->array[i] = a;
  }

  printf("list of numbers:\n");
  display_array_void(numbers, &display_number);

  ArrayVoid_ptr double_of_numbers = map_void(numbers, &give_double_of);
  printf("double of numbers:\n");
  display_array_void(double_of_numbers, &display_number);
}

int main(void)
{
  perform_array_methods();
  perform_array_void_methods();
}