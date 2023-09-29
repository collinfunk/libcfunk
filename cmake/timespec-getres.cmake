include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

check_c_symbol("timespec_getres" "time.h")
check_c_symbol("clock_getres" "time.h")

set(LIBCFUNK_DECLARE_TIMESPEC_GETRES "1" CACHE INTERNAL "")

if (NOT HAVE_TIMESPEC_GETRES)
  # FIXME
  if (NOT HAVE_CLOCK_GETRES)
    message(FATAL_ERROR "Could not implement timespec_getres on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/timespec-getres.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()
