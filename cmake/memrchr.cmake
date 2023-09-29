include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("memrchr" "string.h")

set(LIBCFUNK_DECLARE_MEMRCHR "1" CACHE INTERNAL "")

if (NOT HAVE_MEMRCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memrchr.c
  )
endif ()
