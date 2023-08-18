
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(timingsafe_bcmp "string.h" HAVE_TIMINGSAFE_BCMP)

set(LIBCFUNK_DECLARE_TIMINGSAFE_BCMP 1)

if (NOT HAVE_TIMINGSAFE_BCMP)
  set(HAVE_TIMINGSAFE_BCMP 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/timingsafe-bcmp.c
  )
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-timingsafe-bcmp.cmake)
endif ()

