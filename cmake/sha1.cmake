
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/circular-shift.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/bswap.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/sha1.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/sha1.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sha1.cmake)
endif ()
