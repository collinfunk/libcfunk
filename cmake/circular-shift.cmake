
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/circular-shift.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-circular-shift.cmake)
endif ()

