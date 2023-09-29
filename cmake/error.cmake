
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/error-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/program-name.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strerror-r.cmake)

check_c_symbol("error_message_count" "error.h")
check_c_symbol("error_one_per_line" "error.h")
check_c_symbol("error_print_progname" "error.h")
check_c_symbol("error" "error.h")
check_c_symbol("error_at_line" "error.h")

if (NOT HAVE_ERROR_MESSAGE_COUNT OR NOT HAVE_ERROR_ONE_PER_LINE
    OR NOT HAVE_ERROR_PRINT_PROGNAME OR NOT HAVE_ERROR
    OR NOT HAVE_ERROR_AT_LINE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/error.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-error.cmake)
endif ()

