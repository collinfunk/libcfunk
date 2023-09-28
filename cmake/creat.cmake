
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_FCNTL_H)
  check_symbol_exists("creat" "fcntl.h" HAVE_CREAT)
else ()
  set(HAVE_CREAT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_CREAT "1" CACHE INTERNAL "")

if (NOT HAVE_CREAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/creat.c
  )
endif ()
