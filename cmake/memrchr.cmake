
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memrchr" "string.h" HAVE_MEMRCHR)
endif ()

set(LIBCFUNK_DECLARE_MEMRCHR "1" CACHE STRING "")

if (NOT HAVE_MEMRCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memrchr.c
  )
endif ()
