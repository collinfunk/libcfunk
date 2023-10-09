
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/sockets.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/sockets.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sockets.cmake)
endif ()

