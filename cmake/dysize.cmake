
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/time.cmake)

check_symbol_exists(dysize "time.h" HAVE_DYSIZE)

set(LIBCFUNK_DECLARE_DYSIZE 1)

if (NOT HAVE_DYSIZE)
  set(HAVE_DYSIZE 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/dysize.c
  )
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-dysize.cmake)
endif ()

