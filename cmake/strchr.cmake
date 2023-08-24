
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strchr "string.h" HAVE_STRCHR)

set(LIBCFUNK_DECLARE_STRCHR 1)

if (NOT HAVE_STRCHR)
  set(HAVE_STRCHR 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strchr.c
  )
endif ()
