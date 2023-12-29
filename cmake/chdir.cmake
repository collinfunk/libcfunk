
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("chdir" "unistd.h" HAVE_CHDIR)
  check_symbol_exists("_chdir" "unistd.h" HAVE__CHDIR)
endif ()

set(LIBCFUNK_DECLARE_CHDIR "1" CACHE STRING "")

# Work around an errno bug on MinGW.
check_include_file("windows.h" HAVE_WINDOWS_H)
if (HAVE_WINDOWS_H)
  set(LIBCFUNK_REPLACE_CHDIR "1" CACHE STRING "")
endif ()

if (NOT HAVE_CHDIR OR LIBCFUNK_REPLACE_CHDIR)
  if (NOT HAVE_CHDIR AND NOT HAVE__CHDIR)
    message(FATAL_ERROR "No implementation for 'chdir' on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/chdir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-chdir.cmake)
endif ()

