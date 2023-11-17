
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/arpa-inet-h.cmake)

check_symbol_exists("inet_ntoa" "${CMAKE_EXTRA_INCLUDE_FILES}" HAVE_INET_NTOA)

set(LIBCFUNK_DECLARE_INET_NTOA "1" CACHE STRING "")

if (NOT HAVE_INET_NTOA OR LIBCFUNK_REPLACE_INET_NTOA)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/inet_ntoa.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-inet_ntoa.cmake)
endif ()

