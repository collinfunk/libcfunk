
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/locale-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

if (HAVE_LOCALE_H)
  check_symbol_exists("localeconv" "locale.h" HAVE_LOCALECONV)
endif ()

set(LIBCFUNK_DECLARE_LOCALECONV "1" CACHE STRING "")

if (NOT HAVE_LOCALECONV)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/localeconv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-localeconv.cmake)
endif ()

