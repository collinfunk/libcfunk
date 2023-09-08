
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("ffs" "strings.h" HAVE_FFS)
  check_symbol_exists("ffsl" "strings.h" HAVE_FFSL)
  check_symbol_exists("ffsll" "strings.h" HAVE_FFSLL)
else ()
  set (HAVE_FFS "" CACHE INTERNAL "")
  set (HAVE_FFSL "" CACHE INTERNAL "")
  set (HAVE_FFSLL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FFS "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FFSL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FFSLL "1" CACHE INTERNAL "")

if (NOT HAVE_FFS)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/ffs.c
  )
endif ()

if (NOT HAVE_FFSL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/ffsl.c
  )
endif ()

if (NOT HAVE_FFSLL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/ffsll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-ffs.cmake)
endif ()