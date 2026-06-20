#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Object snek_object_t;
typedef enum {
  INTEGER,
  FLOAT,
  STRING,
  VECTOR3,
  ARRAY,
} snek_object_kind_t;

typedef struct {
  size_t size;
  snek_object_t **elements;

} snek_array_t;

typedef struct Vector {
  snek_object_t *x;
  snek_object_t *y;
  snek_object_t *z;
} snek_vector_t;

typedef union {
  int v_int;
  float v_float;
  char *v_string;
  snek_vector_t v_vector3;
  snek_array_t v_array;
} snek_object_data_t;

typedef struct Object {
  snek_object_kind_t kind;
  snek_object_data_t data;
} snek_object_t;
