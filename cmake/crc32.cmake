
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdint.cmake)

libcfunk_add_sources("crc32.h;crc32.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-crc32.cmake)
endif ()

