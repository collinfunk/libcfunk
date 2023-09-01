
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include(${LIBCFUNK_MODULE_DIR}/bswap.cmake)
include(${LIBCFUNK_MODULE_DIR}/circular-shift.cmake)

libcfunk_add_sources("md5.h;md5.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-md5.cmake)
endif ()

