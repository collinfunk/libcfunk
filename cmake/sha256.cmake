
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include(${LIBCFUNK_MODULE_DIR}/bswap.cmake)
include(${LIBCFUNK_MODULE_DIR}/circular-shift.cmake)

libcfunk_add_sources("sha256.h;sha256.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-sha224.cmake)
  include(${LIBCFUNK_MODULE_DIR}/test-sha256.cmake)
endif ()

