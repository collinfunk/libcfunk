
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

check_symbol_exists(bzero "strings.h" HAVE_BZERO)

set(LIBCFUNK_DECLARE_BZERO 1)

if (NOT HAVE_BZERO)
  set(HAVE_BZERO 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/bzero.c
  )
endif ()

