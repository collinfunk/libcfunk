
include_guard(GLOBAL)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/filename.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/filename.h
)
