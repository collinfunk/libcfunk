include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_c_symbol("getusershell" "unistd.h")
check_c_symbol("setusershell" "unistd.h")
check_c_symbol("endusershell" "unistd.h")

set(LIBCFUNK_DECLARE_ENDUSERSHELL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_GETUSERSHELL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SETUSERSHELL "1" CACHE INTERNAL "")

if (NOT HAVE_GETUSERHSELL OR NOT HAVE_ENDUSERSHELL OR NOT HAVE_SETUSERSHELL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getusershell.c
  )
endif ()
