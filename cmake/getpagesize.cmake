
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd.cmake)

check_symbol_exists(getpagesize "unistd.h" HAVE_GETPAGESIZE)

set(LIBCFUNK_DECLARE_GETPAGESIZE 1)

if (NOT HAVE_GETPAGESIZE)
  set(HAVE_GETPAGESIZE 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getpagesize.c
  )
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-getpagesize.cmake)
endif ()
