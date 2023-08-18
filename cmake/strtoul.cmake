
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

check_symbol_exists(strtoul "stdlib.h" HAVE_STRTOUL)
check_symbol_exists(strtoull "stdlib.h" HAVE_STRTOULL)

set(LIBCFUNK_DECLARE_STRTOUL 1)
set(LIBCFUNK_DECLARE_STRTOULL 1)

if (NOT HAVE_STRTOUL)
  set(HAVE_STRTOUL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtoul.c
  )
endif ()

if (NOT HAVE_STRTOULL)
  set(HAVE_STRTOULL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtoull.c
  )
endif ()
