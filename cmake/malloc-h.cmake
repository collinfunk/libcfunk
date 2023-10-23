
include_guard(GLOBAL)

# Generate <malloc.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_MALLOC_H "1" CACHE INTERNAL "")

check_include_file("malloc.h" HAVE_MALLOC_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-malloc-h.cmake)
endif ()

