
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strncat "string.h" HAVE_STRNCAT)

set(LIBCFUNK_DECLARE_STRNCAT 1)

if (NOT HAVE_STRNCAT)
  set(HAVE_STRNCAT 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strncat.c
  )
endif ()
