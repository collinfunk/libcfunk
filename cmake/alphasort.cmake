
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("alphasort" "dirent.h" HAVE_ALPHASORT)
endif ()

set(LIBCFUNK_DECLARE_ALPHASORT "1" CACHE STRING "")

if (NOT HAVE_ALPHASORT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/alphasort.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-alphasort.cmake)
endif ()

