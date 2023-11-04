
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

# Check for a declaration of gethostname in unistd.h
if (HAVE_UNISTD_H)
  check_symbol_exists("gethostname" "unistd.h" HAVE_GETHOSTNAME)
endif ()

set(LIBCFUNK_DECLARE_GETHOSTNAME "1" CACHE STRING "")

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_WINDOWS_H)
  # Replace the declaration in winsock2.h.
  include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)
  set(LIBCFUNK_REPLACE_GETHOSTNAME "1" CACHE STRING "")
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/gethostname.c
  )
elseif (NOT HAVE_GETHOSTNAME)
  # Use uname and the nodename field of 'struct utsname'.
  check_include_file("sys/utsname.h" HAVE_SYS_UTSNAME_H)
  if (HAVE_SYS_UTSNAME_H)
    check_symbol_exists("uname" "sys/utsname.h" HAVE_UNAME)
  else ()
    set(HAVE_UNAME "" CACHE STRING "")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/gethostname.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-gethostname.cmake)
endif ()

