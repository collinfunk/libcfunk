
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("telldir" "dirent.h" HAVE_TELLDIR)
endif ()

set(LIBCFUNK_DECLARE_TELLDIR "1" CACHE STRING "")

if (NOT HAVE_TELLDIR OR LIBCFUNK_REPLACE_TELLDIR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/telldir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-telldir.cmake)
endif ()

