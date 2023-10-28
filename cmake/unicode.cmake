
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/unicode.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf8-mblen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf16-mblen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf32-mblen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf8-mbtowc.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf16-mbtowc.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf32-mbtowc.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf8-strcpy.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf16-strcpy.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf32-strcpy.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf8-stpcpy.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf16-stpcpy.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf32-stpcpy.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf8-strlen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf16-strlen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf32-strlen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf8-strcat.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf16-strcat.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf32-strcat.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf8-strnlen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf16-strnlen.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/utf32-strnlen.c
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf8-mblen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf16-mblen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf32-mblen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf8-mbtowc.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf16-mbtowc.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf32-mbtowc.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf8-strcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf16-strcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf32-strcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf8-stpcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf16-stpcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf32-stpcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf8-strlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf16-strlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf32-strlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf8-strcat.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf16-strcat.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf32-strcat.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf8-strnlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf16-strnlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utf32-strnlen.cmake)
endif ()

