
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd.cmake)

libcfunk_check_symbol_exists(getpagesize "unistd.h" HAVE_GETPAGESIZE)

set(LIBCFUNK_DECLARE_GETPAGESIZE 1)

if (NOT HAVE_GETPAGESIZE)
  libcfunk_add_sources("getpagesize.c")
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-getpagesize.cmake)
endif ()
