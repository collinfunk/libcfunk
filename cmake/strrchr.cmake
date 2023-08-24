
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strrchr "string.h" HAVE_STRRCHR)

set(LIBCFUNK_DECLARE_STRRCHR 1)

if (NOT HAVE_STRRCHR)
  set(HAVE_STRRCHR 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strrchr.c
  )
endif ()
