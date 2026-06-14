#include "bootlib.h"
#include <stddef.h>
#include <string.h>

void swap(void *vp1, void *vp2, size_t size) {
  void *temp = malloc(size);
  memcpy(temp, vp1, size);
  memcpy(vp1, vp2, size);
  memcpy(vp2, temp, size);
}
