
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_c_symbol("ttyname_r" "unistd.h")
check_c_symbol("ttyname" "unistd.h")

set(LIBCFUNK_DECLARE_TTYNAME_R "1" CACHE INTERNAL "")

if (NOT HAVE_TTYNAME_R)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ttyname-r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ttyname-r.cmake)
endif ()
