
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("popcount" "strings.h" HAVE_POPCOUNT)
  check_symbol_exists("popcountl" "strings.h" HAVE_POPCOUNTL)
  check_symbol_exists("popcountll" "strings.h" HAVE_POPCOUNTLL)
else ()
  set (HAVE_POPCOUNT "" CACHE INTERNAL "")
  set (HAVE_POPCOUNTL "" CACHE INTERNAL "")
  set (HAVE_POPCOUNTLL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_POPCOUNT "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_POPCOUNTL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_POPCOUNTLL "1" CACHE INTERNAL "")

if (NOT HAVE_POPCOUNT)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/popcount.c
  )
endif ()

if (NOT HAVE_POPCOUNTL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/popcountl.c
  )
endif ()

if (NOT HAVE_POPCOUNTLL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/popcountll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-popcount.cmake)
endif ()

