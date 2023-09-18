
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdbool-h.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/base64.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/base64.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-base64.cmake)
endif ()
