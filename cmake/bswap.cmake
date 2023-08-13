
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdint.cmake)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/bswap.h
)

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-bswap.cmake)
endif ()
