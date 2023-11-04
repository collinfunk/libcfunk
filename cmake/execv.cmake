
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("execv" "unistd.h" HAVE_EXECV)
  check_symbol_exists("execve" "unistd.h" HAVE_EXECVE)
endif ()

set(LIBCFUNK_DECLARE_EXECV "1" CACHE STRING "")

if (NOT HAVE_EXECV)
  # FIXME
  if (NOT HAVE_EXECVE)
    message(FATAL_ERROR "No implementation is avaiable for `execve'.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execv.c
  )
endif ()
