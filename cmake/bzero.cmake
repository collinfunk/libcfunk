
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("bzero" "strings.h" HAVE_BZERO)
else ()
  set (HAVE_BZERO "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_BZERO "1" CACHE INTERNAL "")

if (NOT HAVE_BZERO)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/bzero.c
  )
endif ()

