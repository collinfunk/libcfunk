
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("pwrite" "unistd.h" HAVE_PWRITE)
else ()
  set(HAVE_PWRITE "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_PWRITE "1" CACHE INTERNAL "")

if (NOT HAVE_PWRITE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/pwrite.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-pwrite.cmake)
endif ()
