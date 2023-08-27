
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strcat "string.h" HAVE_STRCAT)

set(LIBCFUNK_DECLARE_STRCAT 1)

if (NOT HAVE_STRCAT)
  set(HAVE_STRCAT 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strcat.c
  )
endif ()
