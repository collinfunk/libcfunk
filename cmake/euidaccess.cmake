
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/eaccess.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("euidaccess" "unistd.h" HAVE_EUIDACCESS)
  check_symbol_exists("faccessat" "unistd.h" HAVE_FACCESSAT)
else ()
  set(HAVE_EUIDACCESS "" CACHE INTERNAL "")
  set(HAVE_FACCESSAT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_EUIDACCESS "1" CACHE INTERNAL "")

if (NOT HAVE_EUIDACCESS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/euidaccess.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-euidaccess.cmake)
endif ()

