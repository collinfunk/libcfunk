
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/circular-shift.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/bswap.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/md5.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/md5.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-md5.cmake)
endif ()

