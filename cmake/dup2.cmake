
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

# Check for dup2 or _dup2.
if (HAVE_UNISTD_H)
  check_symbol_exists("dup2" "unistd.h" HAVE_DUP2)
  check_symbol_exists("_dup2" "unistd.h" HAVE__DUP2)
endif ()

set(LIBCFUNK_DECLARE_DUP2 "1" CACHE STRING "")

if (NOT HAVE_DUP2)
  if (NOT HAVE__DUP2)
    check_include_file("fcntl.h" HAVE_FCNTL_H)
    if (HAVE_FCNTL_H)
      check_symbol_exists("fcntl" "fcntl.h" HAVE_FCNTL)
    else ()
      set(HAVE_FCNTL "" CACHE STRING "")
    endif ()
    if (NOT HAVE_FCNTL)
      message(FATAL_ERROR "No implementation of dup2 for your system.")
    endif ()
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/dup2.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-dup2.cmake)
endif ()
