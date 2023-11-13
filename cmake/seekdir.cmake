
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("seekdir" "dirent.h" HAVE_SEEKDIR)
endif ()

set(LIBCFUNK_DECLARE_SEEKDIR "1" CACHE STRING "")

if (NOT HAVE_SEEKDIR OR LIBCFUNK_REPLACE_SEEKDIR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/seekdir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-seekdir.cmake)
endif ()

