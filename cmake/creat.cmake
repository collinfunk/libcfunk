
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

check_c_symbol("creat" "fcntl.h")

set(LIBCFUNK_DECLARE_CREAT "1" CACHE INTERNAL "")

if (NOT HAVE_CREAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/creat.c
  )
endif ()
