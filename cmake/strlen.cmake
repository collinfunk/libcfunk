
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strlen "string.h" HAVE_STRLEN)

set(LIBCFUNK_DECLARE_STRLEN 1)

if (NOT HAVE_STRLEN)
  set(HAVE_STRLEN 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strlen.c
  )
endif ()
