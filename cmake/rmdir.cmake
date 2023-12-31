
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H OR HAVE_HAVE_DIRECT_H)
  set(RMDIR_INCLUDES "")
  if (HAVE_UNISTD_H)
    list(APPEND RMDIR_INCLUDES "unistd.h")
  endif ()
  if (HAVE_DIRECT_H)
    list(APPEND RMDIR_INCLUDES "direct.h")
  endif ()
  check_symbol_exists("rmdir" "${RMDIR_INCLUDES}" HAVE_RMDIR)
  check_symbol_exists("_rmdir" "${RMDIR_INCLUDES}" HAVE__RMDIR)
  unset(RMDIR_INCLUDES)
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)
if (HAVE_WINDOWS_H)
  set(LIBCFUNK_REPLACE_RMDIR "1" CACHE STRING "")
endif ()

set(LIBCFUNK_DECLARE_RMDIR "1" CACHE STRING "")

if (NOT HAVE_RMDIR OR LIBCFUNK_REPLACE_RMDIR)
  if (NOT HAVE_RMDIR AND NOT HAVE__RMDIR)
    message(FATAL_ERROR "No implementation of rmdir on your system.")
  endif ()
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/filename.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/rmdir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-rmdir.cmake)
endif ()

