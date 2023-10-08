
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("mkfifo" "sys/stat.h" HAVE_MKFIFO)
else ()
  set(HAVE_MKFIFO "" CACHE INTERNAL "")
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)

set(LIBCFUNK_DECLARE_MKFIFO "1" CACHE INTERNAL "")

if (NOT HAVE_MKFIFO)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mkfifo.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mkfifo.cmake)
endif ()

