
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

# Doesn't make sense to put these separately.
libcfunk_check_symbol_exists(popcount "strings.h" HAVE_POPCOUNT)
libcfunk_check_symbol_exists(popcountl "strings.h" HAVE_POPCOUNTL)
libcfunk_check_symbol_exists(popcountll "strings.h" HAVE_POPCOUNTLL)

set(LIBCFUNK_DECLARE_POPCOUNT 1)
set(LIBCFUNK_DECLARE_POPCOUNTL 1)
set(LIBCFUNK_DECLARE_POPCOUNTLL 1)

if (NOT HAVE_POPCOUNT)
  libcfunk_add_sources("popcount.c")
endif()

if (NOT HAVE_POPCOUNTL)
  libcfunk_add_sources("popcountl.c")
endif()

if (NOT HAVE_POPCOUNTLL)
  libcfunk_add_sources("popcountll.c")
endif()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-popcount.cmake)
endif ()

