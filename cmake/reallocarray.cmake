
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

check_symbol_exists(reallocarray "stdlib.h" HAVE_REALLOCARRAY)

set(LIBCFUNK_DECLARE_REALLOCARRAY 1)

if (NOT HAVE_REALLOCARRAY)
  set(HAVE_REALLOCARRAY 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/reallocarray.c
  )
endif()

