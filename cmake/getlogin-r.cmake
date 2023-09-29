
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_c_symbol("getlogin_r" "unistd.h")

set(LIBCFUNK_DECLARE_GETLOGIN_R "1" CACHE INTERNAL "")

if (NOT HAVE_GETLOGIN_R)
  check_c_system_headers("windows.h")
  if (NOT HAVE_WINDOWS_H)
    message(FATAL_ERROR "No implemented replacement for getlogin_r(3).")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getlogin-r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getlogin-r.cmake)
endif ()
