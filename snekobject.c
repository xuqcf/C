#include "snekobject.h"
#include <stdlib.h>
#include <string.h>

snek_object_t *new_snek_string(char *value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));

  if (obj == NULL) {
    return NULL;
  }

  int size = strlen(value);

  char *ptr_obj = malloc(size + 1);

  if (ptr_obj == NULL) {
    return NULL;
    free(obj);
  }

  strcpy(ptr_obj, value);

  obj->kind = STRING;

  obj->data.v_string = ptr_obj;

  return obj;
}

// don't touch below this line

snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}

snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}
