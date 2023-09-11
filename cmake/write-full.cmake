
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/write-nointr.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/write-full.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/write-full.h
)
