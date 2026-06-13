#ifndef BOOTLIB_H
#define BOOTLIB_H

#include <stdlib.h>

static int _boot_alloc_count = 0;

static void *_boot_malloc(size_t size) {
  _boot_alloc_count++;
  return malloc(size);
}

static void _boot_free(void *ptr) {
  if (ptr) _boot_alloc_count--;
  free(ptr);
}

static int boot_all_freed(void) {
  return _boot_alloc_count == 0;
}

#define malloc _boot_malloc
#define free _boot_free

#endif
