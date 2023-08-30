
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

check_symbol_exists(mkdtemp "stdlib.h" HAVE_MKDTEMP)

set(LIBCFUNK_DECLARE_MKDTEMP 1)

if (NOT HAVE_MKDTEMP)
  set(HAVE_MKDTEMP 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/mkdtemp.c
  )
endif ()
