
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("opendir" "dirent.h" HAVE_OPENDIR)
endif ()

set(LIBCFUNK_DECLARE_OPENDIR "1" CACHE STRING "")

if (NOT HAVE_OPENDIR OR LIBCFUNK_REPLACE_OPENDIR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/opendir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-opendir.cmake)
endif ()

