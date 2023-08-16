
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strcasecmp "string.h" HAVE_STRCASECMP)

set(LIBCFUNK_DECLARE_STRCASECMP 1)

if (NOT HAVE_STRCASECMP)
  set(HAVE_STRCASECMP 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strcasecmp.c
  )
endif ()
