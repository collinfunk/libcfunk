
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(memchr "string.h" HAVE_MEMCHR)

set(LIBCFUNK_DECLARE_MEMCHR 1)

if (NOT HAVE_MEMCHR)
  set(HAVE_MEMCHR 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memchr.c
  )
endif ()
