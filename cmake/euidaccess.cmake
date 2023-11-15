
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("euidaccess" "unistd.h" HAVE_EUIDACCESS)
endif ()

set(LIBCFUNK_DECLARE_EUIDACCESS "1" CACHE STRING "")

if (NOT HAVE_EUIDACCESS)
  if (HAVE_UNISTD_H)
    check_symbol_exists("faccessat" "unistd.h" HAVE_FACCESSAT)
    check_symbol_exists("eaccess" "unistd.h" HAVE_EACCESS)
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/euidaccess.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-euidaccess.cmake)
endif ()

