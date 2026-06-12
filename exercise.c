#include "exercise.h"
#include <stdio.h>
#include <stdlib.h>

int *allocate_scalar_array(int size, int multiplier) {
  int *allocation = malloc(size * sizeof(int));

  if (allocation == NULL) {
    return NULL;
  }

  int i = 0;

  while (i < size) {
    allocation[i] = i * multiplier;
    i++;
  }

  return;
}
