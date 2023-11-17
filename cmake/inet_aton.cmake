
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/arpa-inet-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/isascii.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/isspace.cmake)

check_symbol_exists("inet_aton" "${CMAKE_EXTRA_INCLUDE_FILES}" HAVE_INET_ATON)

set(LIBCFUNK_DECLARE_INET_ATON "1" CACHE STRING "")

if (NOT HAVE_INET_ATON OR LIBCFUNK_REPLACE_INET_ATON)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/inet_aton.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-inet_aton.cmake)
endif ()

