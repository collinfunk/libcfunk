
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("closedir" "dirent.h" HAVE_CLOSEDIR)
endif ()

set(LIBCFUNK_DECLARE_CLOSEDIR "1" CACHE STRING "")

if (NOT HAVE_CLOSEDIR OR LIBCFUNK_REPLACE_CLOSEDIR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/closedir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

