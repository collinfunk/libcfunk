
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_c_symbol("chown" "unistd.h")

set(LIBCFUNK_DECLARE_CHOWN "1" CACHE INTERNAL "")

if (NOT HAVE_CHOWN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/chown.c
  )
endif ()
