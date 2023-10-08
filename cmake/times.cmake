
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-times-h.cmake)

if (HAVE_SYS_TIMES_H)
  check_symbol_exists("times" "sys/times.h" HAVE_TIMES)
else ()
  set(HAVE_TIMES "" CACHE INTERNAL "")
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)

set(LIBCFUNK_DECLARE_TIMES "1" CACHE INTERNAL "")

if (NOT HAVE_TIMES)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/times.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-times.cmake)
endif ()

