#include "snekstack.h"
#include "bootlib.h"

stack_t *stack_new(size_t capacity) {
  stack_t *mem = malloc(sizeof(stack_t));

  if (mem == NULL) {
    return NULL;
  }

  mem->count = 0;

  mem->capacity = capacity;

  mem->data = malloc(capacity * sizeof(void *));

  if (mem->data == NULL) {
    free(mem);
    return NULL;
  }

  return mem;
}
