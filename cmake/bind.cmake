
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

set(LIBCFUNK_DECLARE_BIND "1" CACHE INTERNAL "")

if (HAVE_WINSOCK2_H)
  include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
  set(LIBCFUNK_REPLACE_BIND "1" CACHE INTERNAL "")
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bind.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-bind.cmake)
endif ()

