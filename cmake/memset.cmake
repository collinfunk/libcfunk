
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(memset "string.h" HAVE_MEMSET)

set(LIBCFUNK_DECLARE_MEMSET 1)

if (NOT HAVE_MEMSET)
  set(HAVE_MEMSET 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memset.c
  )
endif ()
