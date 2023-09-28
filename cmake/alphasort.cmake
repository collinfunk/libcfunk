
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("alphasort" "dirent.h" HAVE_ALPHASORT)
else ()
  set(HAVE_ALPHASORT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ALPHASORT "1" CACHE INTERNAL "")

if (NOT HAVE_ALPHASORT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/alphasort.c
  )
endif ()
