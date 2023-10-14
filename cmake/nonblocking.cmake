
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/nonblocking.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/nonblocking.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-nonblocking.cmake)
endif ()
