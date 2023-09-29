
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/eaccess.cmake)

check_c_symbol("euidaccess" "unistd.h")
check_c_symbol("faccessat" "unistd.h")

set(LIBCFUNK_DECLARE_EUIDACCESS "1" CACHE INTERNAL "")

if (NOT HAVE_EUIDACCESS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/euidaccess.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-euidaccess.cmake)
endif ()

