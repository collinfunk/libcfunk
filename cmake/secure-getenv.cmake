
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("secure_getenv" "stdlib.h" HAVE_SECURE_GETENV)
endif ()

set(LIBCFUNK_DECLARE_SECURE_GETENV "1" CACHE INTERNAL "")

if (NOT HAVE_SECURE_GETENV)
  check_symbol_exists("issetugid" "unistd.h" HAVE_ISSETUGID)
  check_symbol_exists("getgid" "unistd.h" HAVE_GETGID)
  check_symbol_exists("getegid" "unistd.h" HAVE_GETEGID)
  check_symbol_exists("getuid" "unistd.h" HAVE_GETUID)
  check_symbol_exists("geteuid" "unistd.h" HAVE_GETEUID)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/secure-getenv.c
  )
endif ()

