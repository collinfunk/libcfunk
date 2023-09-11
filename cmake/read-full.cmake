
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/read-nointr.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/read-full.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/read-full.h
)
