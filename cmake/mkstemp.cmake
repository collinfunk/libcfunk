
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)
include(${LIBCFUNK_MODULE_DIR}/getrandom.cmake)

check_symbol_exists(mkstemp "stdlib.h" HAVE_MKSTEMP)

set(LIBCFUNK_DECLARE_MKSTEMP 1)

if (NOT HAVE_MKSTEMP)
  set(HAVE_MKSTEMP 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/mkstemp.c
  )
endif ()
