
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdint.cmake)

libcfunk_add_sources("bswap.h")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-bswap.cmake)
endif ()
