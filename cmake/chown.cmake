
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("chown" "unistd.h" HAVE_CHOWN)
else ()
  set(HAVE_CHOWN "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_CHOWN "1" CACHE INTERNAL "")

if (NOT HAVE_CHOWN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/chown.c
  )
endif ()