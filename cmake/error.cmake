
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/error-h.cmake)

if (HAVE_ERROR_H)
  check_symbol_exists("error_message_count" "error.h" HAVE_ERROR_MESSAGE_COUNT)
  check_symbol_exists("error_one_per_line" "error.h" HAVE_ERROR_ONE_PER_LINE)
  check_symbol_exists("error_print_progname" "error.h" HAVE_ERROR_PRINT_PROGNAME)
  check_symbol_exists("error" "error.h" HAVE_ERROR)
  check_symbol_exists("error_at_line" "error.h" HAVE_ERROR_AT_LINE)
endif ()

if (NOT HAVE_ERROR_MESSAGE_COUNT OR NOT HAVE_ERROR_ONE_PER_LINE
    OR NOT HAVE_ERROR_PRINT_PROGNAME OR NOT HAVE_ERROR
    OR NOT HAVE_ERROR_AT_LINE)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getprogname.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strerror_r.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/error.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-error.cmake)
endif ()

