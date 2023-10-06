
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-utsname-h.cmake)

if (HAVE_SYS_UTSNAME_H)
  check_symbol_exists("uname" "sys/utsname.h" HAVE_UNAME)
else ()
  set(HAVE_UNAME "" CACHE INTERNAL "")
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_WINDOWS_H)
  check_include_files("windows.h;sysinfoapi.h" HAVE_SYSINFOAPI_H)
  target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "ws2_32")
else ()
  set(HAVE_SYSINFOAPI_H "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_UNAME "1" CACHE INTERNAL "")

if (NOT HAVE_UNAME)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/uname.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-uname.cmake)
endif ()

