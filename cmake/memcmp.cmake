
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(memcmp "string.h" HAVE_MEMCMP)

set(LIBCFUNK_DECLARE_MEMCMP 1)

if (NOT HAVE_MEMCMP)
  set(HAVE_MEMCMP 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memcmp.c
  )
endif ()
