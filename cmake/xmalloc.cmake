
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/reallocarray.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/xmalloc.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/xmalloc.h
)

