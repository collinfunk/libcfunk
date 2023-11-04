
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("sys/loadavg.h" HAVE_SYS_LOADAVG_H)

if (HAVE_STDLIB_H OR HAVE_SYS_LOADAVG_H)
  set(GETLOADAVG_INCLUDES "")
  if (HAVE_STDLIB_H)
    list(APPEND GETLOADAVG_INCLUDES "stdlib.h")
  endif ()
  if (HAVE_SYS_LOADAVG_H)
    list(APPEND GETLOADAVG_INCLUDES "sys/loadavg.h")
  endif ()
  check_symbol_exists("getloadavg" "${GETLOADAVG_INCLUDES}" HAVE_GETLOADAVG)
  unset(GETLOADAVG_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_GETLOADAVG "1" CACHE STRING "")

if (NOT HAVE_GETLOADAVG)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getloadavg.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getloadavg.cmake)
endif ()

