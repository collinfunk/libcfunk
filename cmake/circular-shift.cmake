
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdint.cmake)
include(${LIBCFUNK_MODULE_DIR}/circular-shift.cmake)

libcfunk_add_sources("circular-shift.h")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-circular-shift.cmake)
endif ()

