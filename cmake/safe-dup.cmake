
include_guard(GLOBAL)

# For _FILENO macros.
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/safe-dup.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/safe-dup.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-safe-dup.cmake)
endif ()

