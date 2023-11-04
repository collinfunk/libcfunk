
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("isatty" "unistd.h" HAVE_ISATTY)
  check_symbol_exists("_isatty" "unistd.h" HAVE__ISATTY)
endif ()

set(LIBCFUNK_DECLARE_ISATTY "1" CACHE STRING "")

if (HAVE__ISATTY OR NOT HAVE_ISATTY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isatty.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-isatty.cmake)
endif ()

