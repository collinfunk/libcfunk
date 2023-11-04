
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

# Check for dup or _dup.
if (HAVE_UNISTD_H)
  check_symbol_exists("dup" "unistd.h" HAVE_DUP)
  check_symbol_exists("_dup" "unistd.h" HAVE__DUP)
endif ()

set(LIBCFUNK_DECLARE_DUP "1" CACHE INTERNAL "")

if (NOT HAVE_DUP)
  if (NOT HAVE__DUP)
    check_include_file("fcntl.h" HAVE_FCNTL_H)
    if (HAVE_FCNTL_H)
      check_symbol_exists("fcntl" "fcntl.h" HAVE_FCNTL)
    else ()
      set(HAVE_FCNTL "" CACHE INTERNAL "")
    endif ()
    if (NOT HAVE_FCNTL)
      message(FATAL_ERROR "No implementation of dup for your system.")
    endif ()
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/dup.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-dup.cmake)
endif ()

