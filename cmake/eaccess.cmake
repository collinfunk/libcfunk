
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/euidaccess.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("eaccess" "unistd.h" HAVE_EACCESS)
endif ()

set(LIBCFUNK_DECLARE_EACCESS "1" CACHE STRING "")

if (NOT HAVE_EACCESS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/eaccess.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-eaccess.cmake)
endif ()

