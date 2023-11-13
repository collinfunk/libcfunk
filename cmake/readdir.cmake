
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("readdir" "dirent.h" HAVE_READDIR)
endif ()

set(LIBCFUNK_DECLARE_READDIR "1" CACHE STRING "")

if (NOT HAVE_READDIR OR LIBCFUNK_REPLACE_READDIR)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

