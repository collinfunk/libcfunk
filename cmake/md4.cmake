
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include(${LIBCFUNK_MODULE_DIR}/bswap.cmake)
include(${LIBCFUNK_MODULE_DIR}/circular-shift.cmake)

libcfunk_add_sources("md4.h;md4.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-md4.cmake)
endif ()
