
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_UNISTD_H)
  check_symbol_exists("ftruncate" "unistd.h" HAVE_FTRUNCATE)
else ()
  set(HAVE_FTRUNCATE "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FTRUNCATE "1" CACHE INTERNAL "")

if (NOT HAVE_FTRUNCATE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ftruncate.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ftruncate.cmake)
endif ()
