
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)

if (HAVE_DIRENT_H)
  check_symbol_exists("scandir" "dirent.h" HAVE_SCANDIR)
endif ()

# TODO
if (NOT HAVE_SCANDIR)
  message(FATAL_ERROR "No implementation of 'scandir' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

