
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/error-h.cmake)
include(${LIBCFUNK_MODULE_DIR}/program-name.cmake)

if (HAVE_ERROR_H)
  check_symbol_exists("error_message_count" "error.h" HAVE_ERROR_MESSAGE_COUNT)
  check_symbol_exists("error_one_per_line" "error.h" HAVE_ERROR_ONE_PER_LINE)
  check_symbol_exists("error_print_progname" "error.h" HAVE_ERROR_PRINT_PROGNAME)
  check_symbol_exists("error" "error.h" HAVE_ERROR)
  check_symbol_exists("error_at_line" "error.h" HAVE_ERROR_AT_LINE)
else ()
  set(HAVE_ERROR_MESSAGE_COUNT CACHE INTERNAL "")
  set(HAVE_ERROR_ONE_PER_LINE "" CACHE INTERNAL "")
  set(HAVE_ERROR_PRINT_PROGNAME "" CACHE INTERNAL "")
  set(HAVE_ERROR "" CACHE INTERNAL "")
  set(HAVE_ERROR_AT_LINE "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_ERROR_MESSAGE_COUNT OR NOT HAVE_ERROR_ONE_PER_LINE
    OR NOT HAVE_ERROR_PRINT_PROGNAME OR NOT HAVE_ERROR
    OR NOT HAVE_ERROR_AT_LINE)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/error.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-error.cmake)
endif ()

