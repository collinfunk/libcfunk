
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("popcount" "strings.h")
check_c_symbol("popcountl" "strings.h")
check_c_symbol("popcountll" "strings.h")

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

