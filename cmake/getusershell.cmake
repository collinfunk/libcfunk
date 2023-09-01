
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd.cmake)

libcfunk_check_symbol_exists(getusershell "unistd.h" HAVE_GETUSERSHELL)
libcfunk_check_symbol_exists(setusershell "unistd.h" HAVE_SETUSERSHELL)
libcfunk_check_symbol_exists(endusershell "unistd.h" HAVE_ENDUSERSHELL)

set(LIBCFUNK_DECLARE_GETUSERSHELL 1)
set(LIBCFUNK_DECLARE_SETUSERSHELL 1)
set(LIBCFUNK_DECLARE_ENDUSERSHELL 1)

if (NOT HAVE_GETUSERSHELL OR NOT HAVE_SETUSERSHELL OR NOT HAVE_ENDUSERSHELL)
  libcfunk_add_sources("getusershell.c")
endif ()

