
include_guard(GLOBAL)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/unicode.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf8-mblen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf16-mblen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf32-mblen.c
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf8-mblen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf16-mblen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf32-mblen.cmake)
endif ()

