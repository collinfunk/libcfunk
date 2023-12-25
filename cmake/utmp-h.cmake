
include_guard(GLOBAL)

# Generate <utmp.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UTMP_H "1" CACHE STRING "")

check_include_file("utmp.h" HAVE_UTMP_H)
check_include_file("libutil.h" HAVE_LIBUTIL_H)
check_include_file("util.h" HAVE_UTIL_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utmp-h.cmake)
endif ()

