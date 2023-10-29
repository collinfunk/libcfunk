
include_guard(GLOBAL)

# Generate <fenv.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FENV_H "1" CACHE INTERNAL "")

check_include_file("fenv.h" HAVE_FENV_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fenv-h.cmake)
endif ()

