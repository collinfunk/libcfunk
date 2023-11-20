
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/arpa-inet-h.cmake)

check_symbol_exists("inet_ntop" "${CMAKE_EXTRA_INCLUDE_FILES}" HAVE_INET_NTOP)

set(LIBCFUNK_DECLARE_INET_NTOP "1" CACHE STRING "")

if (NOT HAVE_INET_NTOP OR LIBCFUNK_REPLACE_INET_NTOP)
  include($CACHE{LIBCFUNK_MODULE_DIR}/snprintf.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/memcpy.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/inet_ntop.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-inet_ntop.cmake)
endif ()

