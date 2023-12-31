
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_FCNTL_H)
  check_symbol_exists("fcntl" "fcntl.h" HAVE_FCNTL)
endif ()

set(LIBCFUNK_DECLARE_FCNTL "1" CACHE STRING "")

if (NOT HAVE_FCNTL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fcntl.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fcntl.cmake)
endif ()

