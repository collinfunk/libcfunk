
include_guard(GLOBAL)

# Generate <sysexits.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYSEXITS_H "1" CACHE INTERNAL "")

check_include_file("sysexits.h" HAVE_SYSEXITS_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sysexits-h.cmake)
endif ()

