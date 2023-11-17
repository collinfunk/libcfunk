
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/arpa-inet-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/inet_aton.cmake)

check_symbol_exists("inet_addr" "${CMAKE_EXTRA_INCLUDE_FILES}" HAVE_INET_ADDR)

set(LIBCFUNK_DECLARE_INET_ADDR "1" CACHE STRING "")

if (NOT HAVE_INET_ADDR OR LIBCFUNK_REPLACE_INET_ADDR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/inet_addr.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-inet_addr.cmake)
endif ()

