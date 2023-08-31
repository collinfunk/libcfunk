
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/program-name.cmake)

check_include_file("error.h" HAVE_ERROR_H)

check_symbol_exists(error_message_count "error.h" HAVE_ERROR_MESSAGE_COUNT)
check_symbol_exists(error_one_per_line "error.h" HAVE_ERROR_ONE_PER_LINE)
check_symbol_exists(error_print_progname "error.h" HAVE_ERROR_PRINT_PROGNAME)
check_symbol_exists(error "error.h" HAVE_ERROR)
check_symbol_exists(error_at_line "error.h" HAVE_ERROR_AT_LINE)

set(LIBCFUNK_GENERATE_ERROR_H TRUE)
set(LIBCFUNK_DECLARE_ERROR_MESSAGE_COUNT 1)
set(LIBCFUNK_DECLARE_ERROR_ONE_PER_LINE 1)
set(LIBCFUNK_DECLARE_ERROR_PRINT_PROGNAME 1)
set(LIBCFUNK_DECLARE_ERROR 1)
set(LIBCFUNK_DECLARE_ERROR_AT_LINE 1)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/error.c
)

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-error.cmake)
endif ()

if (NOT HAVE_ERROR_H)
  set(HAVE_ERROR_H 0)
endif ()

if (NOT HAVE_ERROR_MESSAGE_COUNT)
  set(HAVE_ERROR_MESSAGE_COUNT 0)
endif ()

if (NOT HAVE_ERROR_ONE_PER_LINE)
  set(HAVE_ERROR_ONE_PER_LINE 0)
endif ()

if (NOT HAVE_ERROR_PRINT_PROGNAME)
  set(HAVE_ERROR_PRINT_PROGNAME 0)
endif ()

if (NOT HAVE_ERROR)
  set(HAVE_ERROR 0)
endif ()

if (NOT HAVE_ERROR_AT_LINE)
  set(HAVE_ERROR_AT_LINE 0)
endif ()

