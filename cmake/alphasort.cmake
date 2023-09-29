
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

check_c_symbol("alphasort" "dirent.h")

set(LIBCFUNK_DECLARE_ALPHASORT "1" CACHE INTERNAL "")

if (NOT HAVE_ALPHASORT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/alphasort.c
  )
endif ()

