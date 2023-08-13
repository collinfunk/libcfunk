
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

# Doesn't make sense to put these separately.
check_symbol_exists(popcount "strings.h" HAVE_POPCOUNT)
check_symbol_exists(popcountl "strings.h" HAVE_POPCOUNTL)
check_symbol_exists(popcountll "strings.h" HAVE_POPCOUNTLL)

if (NOT HAVE_POPCOUNT)
  set(HAVE_POPCOUNT 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/popcount.c
  )
endif()

if (NOT HAVE_POPCOUNTL)
  set(HAVE_POPCOUNTL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/popcountl.c
  )
endif()

if (NOT HAVE_POPCOUNTLL)
  set(HAVE_POPCOUNTLL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/popcountll.c
  )
endif()


