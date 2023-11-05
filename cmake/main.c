
#define _GNU_SOURCE 1
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

int
main (void)
{
  printf ("%ju\n", (uintmax_t) UINT8_MAX);
  printf ("%ju\n", (uintmax_t) UINT16_MAX);
  printf ("%ju\n", (uintmax_t) UINT32_MAX);
  printf ("%ju\n", (uintmax_t) UINT64_MAX);

  return 0;
}
