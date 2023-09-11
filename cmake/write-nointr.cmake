
include_guard(GLOBAL)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/write-nointr.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/write-nointr.h
)
