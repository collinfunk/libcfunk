
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("localtime_r" "time.h" HAVE_LOCALTIME_R)
else ()
  set(HAVE_LOCALTIME_R "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_LOCALTIME_R "1" CACHE INTERNAL "")

if (NOT HAVE_LOCALTIME_R)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/localtime-r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-localtime-r.cmake)
endif ()

