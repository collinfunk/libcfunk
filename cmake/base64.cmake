
include_guard(GLOBAL)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/base64.c
  ${LIBCFUNK_SOURCE_DIR}/base64.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-base64.cmake)
endif ()
