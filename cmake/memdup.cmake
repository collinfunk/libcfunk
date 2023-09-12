
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcpy.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/memdup.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/memdup.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-memdup.cmake)
endif ()

