
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("pread" "unistd.h" HAVE_PREAD)
else ()
  set(HAVE_PREAD "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_PREAD "1" CACHE INTERNAL "")

if (NOT HAVE_PREAD)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/pread.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-pread.cmake)
endif ()

