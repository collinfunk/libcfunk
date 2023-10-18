
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("lchown" "unistd.h" HAVE_LCHOWN)
else ()
  set(HAVE_LCHOWN "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_LCHOWN "1" CACHE INTERNAL "")

if (NOT HAVE_LCHOWN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/lchown.c
  )
endif ()

