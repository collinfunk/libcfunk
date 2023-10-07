
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/pipe.cmake)

check_include_file("unixio.h" HAVE_UNIXIO_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_UNIXIO_H)
  check_symbol_exists("isapipe" "unixio.h" HAVE_ISAPIPE)
else ()
  set(HAVE_ISAPIPE "" CACHE INTERNAL "")
endif ()

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/isapipe.h
)

if (NOT HAVE_ISAPIPE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isapipe.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-isapipe.cmake)
endif ()
