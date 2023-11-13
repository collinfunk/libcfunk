
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("rewinddir" "dirent.h" HAVE_REWINDDIR)
endif ()

set(LIBCFUNK_DECLARE_REWINDDIR "1" CACHE STRING "")

if (NOT HAVE_REWINDDIR OR LIBCFUNK_REPLACE_REWINDDIR)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

