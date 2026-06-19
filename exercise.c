#include "exercise.h"
#include "stdlib.h"

void allocate_int(int **pointer_pointer, int value) {
  int *integer = malloc(sizeof(int));
  *pointer_pointer = integer;
  **pointer_pointer = value;
}
c