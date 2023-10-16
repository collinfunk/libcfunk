
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("stat" "sys/stat.h" HAVE_STAT)
  check_symbol_exists("_stat" "sys/stat.h" HAVE__STAT)
else ()
  set(HAVE_STAT "" CACHE INTERNAL "")
  set(HAVE__STAT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STAT "1" CACHE INTERNAL "")

if (NOT HAVE_STAT)
  if (NOT HAVE__STAT)
    message(FATAL_ERROR "No implementation of 'stat' avaliable on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/stat.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stat.cmake)
endif ()

