
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_UNISTD_H)
  check_symbol_exists("usleep" "unistd.h" HAVE_USLEEP)
else ()
  set(HAVE_USLEEP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_USLEEP "1" CACHE INTERNAL "")

if (NOT HAVE_USLEEP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/usleep.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-usleep.cmake)
endif ()

