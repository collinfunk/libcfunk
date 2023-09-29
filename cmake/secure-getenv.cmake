
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_c_symbol("secure_getenv" "stdlib.h")
check_c_symbol("issetugid" "unistd.h")
check_c_symbol("getgid" "unistd.h")
check_c_symbol("getegid" "unistd.h")
check_c_symbol("getuid" "unistd.h")
check_c_symbol("geteuid" "unistd.h")

set(LIBCFUNK_DECLARE_SECURE_GETENV "1" CACHE INTERNAL "")

if (NOT HAVE_SECURE_GETENV)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/secure-getenv.c
  )
endif ()

