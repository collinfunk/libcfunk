
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/read-nointr.cmake)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/read-full.h
  ${LIBCFUNK_SOURCE_DIR}/read-full.c
)

if (LIBCFUNK_BUILD_TESTS)
  # This test uses them both, even though they can be used seperatly
  include(${LIBCFUNK_MODULE_DIR}/write-full.cmake)
  include(${LIBCFUNK_MODULE_DIR}/test-read-write-full.cmake)
endif ()

