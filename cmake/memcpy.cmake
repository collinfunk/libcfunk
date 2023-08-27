
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(memcpy "string.h" HAVE_MEMCPY)

set(LIBCFUNK_DECLARE_MEMCPY 1)

if (NOT HAVE_MEMCPY)
  set(HAVE_MEMCPY 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memcpy.c
  )
endif ()
