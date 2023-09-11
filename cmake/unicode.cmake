
include_guard(GLOBAL)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/unicode.h
  ${LIBCFUNK_SOURCE_DIR}/utf8-mblen.c
  ${LIBCFUNK_SOURCE_DIR}/utf16-mblen.c
  ${LIBCFUNK_SOURCE_DIR}/utf32-mblen.c
)

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-utf8-mblen.cmake)
  include(${LIBCFUNK_MODULE_DIR}/test-utf16-mblen.cmake)
  include(${LIBCFUNK_MODULE_DIR}/test-utf32-mblen.cmake)
endif ()

