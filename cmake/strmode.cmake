
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strmode "string.h" HAVE_STRMODE)

set(LIBCFUNK_DECLARE_STRMODE 1)

if (NOT HAVE_STRMODE)
  set(HAVE_STRMODE 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strmode.c
  )
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-strmode.cmake)
endif ()

