
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mkstemp" "stdlib.h" HAVE_MKSTEMP)
else ()
  set (HAVE_MKSTEMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_MKSTEMP "1" CACHE INTERNAL "")

# Substitution function uses getrandom to make a random filename.
if (NOT HAVE_MKSTEMP)
  include(${LIBCFUNK_MODULE_DIR}/getrandom.cmake)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/mkstemp.c
  )
endif ()

