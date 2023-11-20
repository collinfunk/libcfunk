
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/arpa-inet-h.cmake)

check_symbol_exists("inet_pton" "${CMAKE_EXTRA_INCLUDE_FILES}" HAVE_INET_PTON)

set(LIBCFUNK_DECLARE_INET_PTON "1" CACHE STRING "")

if (NOT HAVE_INET_PTON OR LIBCFUNK_REPLACE_INET_PTON)
  include($CACHE{LIBCFUNK_MODULE_DIR}/memcpy.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/inet_pton.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-inet_pton.cmake)
endif ()

