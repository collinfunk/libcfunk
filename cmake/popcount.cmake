
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("intrin.h" HAVE_INTRIN_H)

if (HAVE_STRINGS_H)
  check_symbol_exists("popcount" "strings.h" HAVE_POPCOUNT)
  check_symbol_exists("popcountl" "strings.h" HAVE_POPCOUNTL)
  check_symbol_exists("popcountll" "strings.h" HAVE_POPCOUNTLL)
endif ()

set(LIBCFUNK_DECLARE_POPCOUNT "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_POPCOUNTL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_POPCOUNTLL "1" CACHE INTERNAL "")

if (NOT HAVE_POPCOUNT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/popcount.c
  )
endif ()

if (NOT HAVE_POPCOUNTL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/popcountl.c
  )
endif ()

if (NOT HAVE_POPCOUNTLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/popcountll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-popcount.cmake)
endif ()

