
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("ttyname_r" "unistd.h" HAVE_TTYNAME_R)
  check_symbol_exists("ttyname" "unistd.h" HAVE_TTYNAME)
else ()
  set(HAVE_TTYNAME_R "" CACHE INTERNAL "")
  set(HAVE_TTYNAME "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_TTYNAME_R "1" CACHE INTERNAL "")

if (NOT HAVE_TTYNAME_R)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ttyname-r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ttyname-r.cmake)
endif ()
