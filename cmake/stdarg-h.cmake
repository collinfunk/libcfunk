
include_guard(GLOBAL)

# Generate <stdarg.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDARG_H "1" CACHE INTERNAL "")

check_include_file("stdarg.h" HAVE_STDARG_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdarg-h.cmake)
endif ()

