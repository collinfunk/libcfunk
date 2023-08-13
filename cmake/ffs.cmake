
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

# Doesn't make sense to put these separately.
check_symbol_exists(ffs "strings.h" HAVE_FFS)
check_symbol_exists(ffsl "strings.h" HAVE_FFSL)
check_symbol_exists(ffsll "strings.h" HAVE_FFSLL)

if (NOT HAVE_FFS)
  set(HAVE_FFS 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/ffs.c
  )
endif()

if (NOT HAVE_FFSL)
  set(HAVE_FFSL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/ffsl.c
  )
endif()

if (NOT HAVE_FFSLL)
  set(HAVE_FFSLL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/ffsll.c
  )
endif()


