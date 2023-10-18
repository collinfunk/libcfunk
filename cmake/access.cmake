
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("access" "unistd.h" HAVE_ACCESS)
  check_symbol_exists("_access" "unistd.h" HAVE__ACCESS)
else ()
  set(HAVE_ACCESS "" CACHE INTERNAL "")
  set(HAVE__ACCESS "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ACCESS "1" CACHE INTERNAL "")

if (NOT HAVE_ACCESS)
  if (NOT HAVE__ACCESS)
    message(FATAL_ERROR "No implementation for 'access' on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/access.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-access.cmake)
endif ()

