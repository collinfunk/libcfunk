include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strcspn" "string.h")

set(LIBCFUNK_DECLARE_STRCSPN "1" CACHE INTERNAL "")

if (NOT HAVE_STRCSPN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcspn.c
  )
endif ()
