
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include(${LIBCFUNK_MODULE_DIR}/bswap.cmake)
include(${LIBCFUNK_MODULE_DIR}/circular-shift.cmake)

libcfunk_add_sources("sha512.h;sha512.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-sha384.cmake)
  include(${LIBCFUNK_MODULE_DIR}/test-sha512.cmake)
endif ()

