
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(rawmemchr "string.h" HAVE_RAWMEMCHR)

set(LIBCFUNK_DECLARE_RAWMEMCHR 1)

if (NOT HAVE_RAWMEMCHR)
  set(HAVE_RAWMEMCHR 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/rawmemchr.c
  )
endif ()
