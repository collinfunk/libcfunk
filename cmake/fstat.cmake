
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("fstat" "sys/stat.h" HAVE_FSTAT)
  check_symbol_exists("_fstat" "sys/stat.h" HAVE__FSTAT)
else ()
  set(HAVE_FSTAT "" CACHE INTERNAL "")
  set(HAVE__FSTAT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FSTAT "1" CACHE INTERNAL "")

if (NOT HAVE_FSTAT)
  if (NOT HAVE__FSTAT)
    message(FATAL_ERROR "No implementation of 'fstat' avaliable on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fstat.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fstat.cmake)
endif ()

