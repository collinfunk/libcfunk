
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

set(LIBCFUNK_DECLARE_RECV "1" CACHE STRING "")

if (HAVE_WINSOCK2_H)
  include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
  set(LIBCFUNK_REPLACE_RECV "1" CACHE STRING "")
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/recv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

