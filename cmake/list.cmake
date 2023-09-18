
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdbool-h.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/list.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/list.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-list.cmake)
endif ()
