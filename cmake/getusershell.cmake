include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getusershell" "unistd.h" HAVE_GETUSERSHELL)
  check_symbol_exists("setusershell" "unistd.h" HAVE_SETUSERSHELL)
  check_symbol_exists("endusershell" "unistd.h" HAVE_ENDUSERSHELL)
endif ()

set(LIBCFUNK_DECLARE_ENDUSERSHELL "1" CACHE STRING "")
set(LIBCFUNK_DECLARE_GETUSERSHELL "1" CACHE STRING "")
set(LIBCFUNK_DECLARE_SETUSERSHELL "1" CACHE STRING "")

if (NOT HAVE_GETUSERHSELL OR NOT HAVE_ENDUSERSHELL OR NOT HAVE_SETUSERSHELL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getusershell.c
  )
endif ()
