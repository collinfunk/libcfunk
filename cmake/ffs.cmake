
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

# Doesn't make sense to put these separately.
libcfunk_check_symbol_exists(ffs "strings.h" HAVE_FFS)
libcfunk_check_symbol_exists(ffsl "strings.h" HAVE_FFSL)
libcfunk_check_symbol_exists(ffsll "strings.h" HAVE_FFSLL)

set(LIBCFUNK_DECLARE_FFS 1)
set(LIBCFUNK_DECLARE_FFSL 1)
set(LIBCFUNK_DECLARE_FFSLL 1)

if (NOT HAVE_FFS)
  libcfunk_add_sources("ffs.c")
endif()

if (NOT HAVE_FFSL)
  libcfunk_add_sources("ffsl.c")
endif()

if (NOT HAVE_FFSLL)
  libcfunk_add_sources("ffsll.c")
endif()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-ffs.cmake)
endif ()
