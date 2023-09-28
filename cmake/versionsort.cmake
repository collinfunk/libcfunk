
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("versionsort" "dirent.h" HAVE_VERSIONSORT)
else ()
  set(HAVE_VERSIONSORT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_VERSIONSORT "1" CACHE INTERNAL "")

if (NOT HAVE_VERSIONSORT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/versionsort.c
  )
endif ()

