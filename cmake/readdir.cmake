
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("readdir" "dirent.h" HAVE_READDIR)
endif ()

set(LIBCFUNK_DECLARE_READDIR "1" CACHE STRING "")

if (NOT HAVE_READDIR OR LIBCFUNK_REPLACE_READDIR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/readdir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-readdir.cmake)
endif ()

