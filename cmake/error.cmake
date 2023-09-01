
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/program-name.cmake)

libcfunk_check_include_file("error.h" HAVE_ERROR_H)

libcfunk_check_symbol_exists(error_message_count "error.h" HAVE_ERROR_MESSAGE_COUNT)
libcfunk_check_symbol_exists(error_one_per_line "error.h" HAVE_ERROR_ONE_PER_LINE)
libcfunk_check_symbol_exists(error_print_progname "error.h" HAVE_ERROR_PRINT_PROGNAME)
libcfunk_check_symbol_exists(error "error.h" HAVE_ERROR)
libcfunk_check_symbol_exists(error_at_line "error.h" HAVE_ERROR_AT_LINE)

set(LIBCFUNK_GENERATE_ERROR_H TRUE)
set(LIBCFUNK_DECLARE_ERROR_MESSAGE_COUNT 1)
set(LIBCFUNK_DECLARE_ERROR_ONE_PER_LINE 1)
set(LIBCFUNK_DECLARE_ERROR_PRINT_PROGNAME 1)
set(LIBCFUNK_DECLARE_ERROR 1)
set(LIBCFUNK_DECLARE_ERROR_AT_LINE 1)

libcfunk_add_sources("error.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-error.cmake)
endif ()
