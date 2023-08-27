
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strncpy "string.h" HAVE_STRNCPY)

set(LIBCFUNK_DECLARE_STRNCPY 1)

if (NOT HAVE_STRNCPY)
  set(HAVE_STRNCPY 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strncpy.c
  )
endif ()
