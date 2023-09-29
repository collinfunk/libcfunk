
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("rindex" "strings.h")

set(LIBCFUNK_DECLARE_RINDEX "1" CACHE INTERNAL "")

if (NOT HAVE_RINDEX)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/rindex.c
  )
endif ()

