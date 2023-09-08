
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mkdtemp" "stdlib.h" HAVE_MKDTEMP)
else ()
  set (HAVE_MKDTEMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_MKDTEMP "1" CACHE INTERNAL "")

# Substitution function uses getrandom to make a random filename.
if (NOT HAVE_MKDTEMP)
  include(${LIBCFUNK_MODULE_DIR}/getrandom.cmake)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/mkdtemp.c
  )
endif ()
