
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(memrchr "string.h" HAVE_MEMRCHR)

set(LIBCFUNK_DECLARE_MEMRCHR 1)

if (NOT HAVE_MEMRCHR)
  set(HAVE_MEMRCHR 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memrchr.c
  )
endif ()
