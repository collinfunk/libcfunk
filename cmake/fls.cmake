
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

# Doesn't make sense to put these separately.
libcfunk_check_symbol_exists(fls "strings.h" HAVE_FLS)
libcfunk_check_symbol_exists(flsl "strings.h" HAVE_FLSL)
libcfunk_check_symbol_exists(flsll "strings.h" HAVE_FLSLL)

set(LIBCFUNK_DECLARE_FLS 1)
set(LIBCFUNK_DECLARE_FLSL 1)
set(LIBCFUNK_DECLARE_FLSLL 1)

if (NOT HAVE_FLS)
  libcfunk_add_sources("fls.c")
endif ()

if (NOT HAVE_FLSL)
  libcfunk_add_sources("flsl.c")
endif ()

if (NOT HAVE_FLSLL)
  libcfunk_add_sources("flsll.c")
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-fls.cmake)
endif ()
