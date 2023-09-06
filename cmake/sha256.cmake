
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include(${LIBCFUNK_MODULE_DIR}/circular-shift.cmake)
include(${LIBCFUNK_MODULE_DIR}/bswap.cmake)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/sha256.c
  ${LIBCFUNK_SOURCE_DIR}/sha256.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-sha224.cmake)
  include(${LIBCFUNK_MODULE_DIR}/test-sha256.cmake)
endif ()
