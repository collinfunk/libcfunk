
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strncasecmp "string.h" HAVE_STRNCASECMP)

set(LIBCFUNK_DECLARE_STRNCASECMP 1)

if (NOT HAVE_STRNCASECMP)
  set(HAVE_STRNCASECMP 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strncasecmp.c
  )
endif ()
