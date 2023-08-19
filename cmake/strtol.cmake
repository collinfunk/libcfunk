
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

check_symbol_exists(strtol "stdlib.h" HAVE_STRTOL)
check_symbol_exists(strtoll "stdlib.h" HAVE_STRTOLL)

set(LIBCFUNK_DECLARE_STRTOL 1)
set(LIBCFUNK_DECLARE_STRTOLL 1)

if (NOT HAVE_STRTOL)
  set(HAVE_STRTOL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtol.c
  )
endif ()

if (NOT HAVE_STRTOLL)
  set(HAVE_STRTOLL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtoll.c
  )
endif ()
