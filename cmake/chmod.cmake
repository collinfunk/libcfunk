
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("chmod" "sys/stat.h" HAVE_CHMOD)
else ()
  set(HAVE_CHMOD "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_CHMOD "1" CACHE INTERNAL "")

if (NOT HAVE_CHMOD)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/chmod.c
  )
endif ()
