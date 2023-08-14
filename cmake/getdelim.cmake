
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdio.cmake)

check_symbol_exists(getdelim "stdio.h" HAVE_GETDELIM)

set(LIBCFUNK_DECLARE_GETDELIM 1)

if (NOT HAVE_GETDELIM)
  set(HAVE_GETDELIM 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getdelim.c
  )
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-getdelim.cmake)
endif ()

