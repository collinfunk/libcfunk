
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/locale-h.cmake)

if (HAVE_LOCALE_H)
  check_symbol_exists("setlocale" "locale.h" HAVE_SETLOCALE)
else ()
  set(HAVE_SETLOCALE "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_SETLOCALE)
  message(FATAL_ERROR "Your system does not have an implementation of 'setlocale'.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-setlocale.cmake)
endif ()

