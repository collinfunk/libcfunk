
include_guard(GLOBAL)

# Generate <libgen.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LIBGEN_H "1" CACHE STRING "")

check_include_file("libgen.h" HAVE_LIBGEN_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-libgen-h.cmake)
endif ()

