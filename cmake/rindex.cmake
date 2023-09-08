
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("rindex" "strings.h" HAVE_RINDEX)
else ()
  set (HAVE_RINDEX "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_RINDEX "1" CACHE INTERNAL "")

if (NOT HAVE_RINDEX)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/rindex.c
  )
endif ()
