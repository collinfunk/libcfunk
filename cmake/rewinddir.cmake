
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("rewinddir" "dirent.h" HAVE_REWINDDIR)
endif ()

set(LIBCFUNK_DECLARE_REWINDDIR "1" CACHE STRING "")

if (NOT HAVE_REWINDDIR OR LIBCFUNK_REPLACE_REWINDDIR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/rewinddir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-rewinddir.cmake)
endif ()

