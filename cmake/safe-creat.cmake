
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/safe-dup.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/safe-creat.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/safe-creat.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-safe-creat.cmake)
endif ()

