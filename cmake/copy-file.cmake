
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/read-nointr.cmake)
include(${LIBCFUNK_MODULE_DIR}/write-full.cmake)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/copy-file.c
  ${LIBCFUNK_SOURCE_DIR}/copy-file.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-copy-file.cmake)
endif ()
