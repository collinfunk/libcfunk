
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(memmove "string.h" HAVE_MEMMOVE)

set(LIBCFUNK_DECLARE_MEMMOVE 1)

if (NOT HAVE_MEMMOVE)
  set(HAVE_MEMMOVE 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memmove.c
  )
endif ()
