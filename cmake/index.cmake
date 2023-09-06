
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("index" "strings.h" HAVE_INDEX)
else ()
  set (HAVE_INDEX "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_INDEX "1" CACHE INTERNAL "")

if (NOT HAVE_INDEX)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/index.c
  )
endif ()

