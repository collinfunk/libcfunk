
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("sethostname" "unistd.h" HAVE_SETHOSTNAME)
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)

set(LIBCFUNK_DECLARE_SETHOSTNAME "1" CACHE INTERNAL "")

if (NOT HAVE_SETHOSTNAME)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sethostname.c
  )
endif ()

