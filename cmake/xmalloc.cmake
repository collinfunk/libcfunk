
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/reallocarray.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/malloc.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/calloc.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/realloc.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/free.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/xmalloc.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/xmalloc.h
)

