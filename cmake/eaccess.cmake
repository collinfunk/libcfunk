
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/euidaccess.cmake)

check_c_symbol("eaccess" "unistd.h")

set(LIBCFUNK_DECLARE_EACCESS "1" CACHE INTERNAL "")

if (NOT HAVE_EACCESS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/eaccess.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-eaccess.cmake)
endif ()

