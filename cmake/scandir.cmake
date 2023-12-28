
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("scandir" "dirent.h" HAVE_SCANDIR)
endif ()

set(LIBCFUNK_DECLARE_SCANDIR "1" CACHE STRING "")

if (NOT HAVE_SCANDIR OR LIBCFUNK_REPLACE_SCANDIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/opendir.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/readdir.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/closedir.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/qsort.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/memcpy.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/scandir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-scandir.cmake)
endif ()

