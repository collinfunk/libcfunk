
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memcpy.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("mempcpy" "string.h" HAVE_MEMPCPY)
else ()
  set(HAVE_MEMPCPY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_MEMPCPY "1" CACHE INTERNAL "")

if (NOT HAVE_MEMPCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mempcpy.c
  )
endif ()
