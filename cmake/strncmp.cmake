
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strncmp "string.h" HAVE_STRNCMP)

set(LIBCFUNK_DECLARE_STRNCMP 1)

if (NOT HAVE_STRNCMP)
  set(HAVE_STRNCMP 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strncmp.c
  )
endif ()
