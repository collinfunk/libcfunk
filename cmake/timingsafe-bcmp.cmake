
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(timingsafe_bcmp "string.h" HAVE_TIMINGSAFE_BCMP)

set(LIBCFUNK_DECLARE_TIMINGSAFE_BCMP 1)

if (NOT HAVE_TIMINGSAFE_BCMP)
  libcfunk_add_sources("timingsafe-bcmp.c")
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-timingsafe-bcmp.cmake)
endif ()

