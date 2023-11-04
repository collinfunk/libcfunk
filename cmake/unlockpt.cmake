
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-ioctl-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("unlockpt" "stdlib.h" HAVE_UNLOCKPT)
endif ()

set(LIBCFUNK_DECLARE_UNLOCKPT "1" CACHE STRING "")

if (NOT HAVE_UNLOCKPT)
  check_symbol_exists("ptsname" "stdlib.h" HAVE_PTSNAME)
  check_symbol_exists("revoke" "unistd.h" HAVE_REVOKE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/unlockpt.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-unlockpt.cmake)
endif ()

