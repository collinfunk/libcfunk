
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sched-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_SCHED_H)
  check_symbol_exists("sched_yield" "sched.h" HAVE_SCHED_YIELD)
endif ()

set(LIBCFUNK_DECLARE_SCHED_YIELD "1" CACHE STRING "")

if (NOT HAVE_SCHED_YIELD)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sched_yield.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sched_yield.cmake)
endif ()

