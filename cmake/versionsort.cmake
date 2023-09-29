
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

check_c_symbol("versionsort" "dirent.h")

set(LIBCFUNK_DECLARE_VERSIONSORT "1" CACHE INTERNAL "")

if (NOT HAVE_VERSIONSORT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/versionsort.c
  )
endif ()

