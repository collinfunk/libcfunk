
include_guard(GLOBAL)

# Generate <stdarg.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDARG_H "1" CACHE STRING "")

check_include_file("stdarg.h" HAVE_STDARG_H)

if (HAVE_STDARG_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "stdarg.h")
  check_type_size("va_list" VA_LIST)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "stdarg.h")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdarg-h.cmake)
endif ()

