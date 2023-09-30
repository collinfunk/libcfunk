include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memcpy" "string.h" HAVE_MEMCPY)
else ()
  set(HAVE_MEMCPY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_MEMCPY "1" CACHE INTERNAL "")

if (NOT HAVE_MEMCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memcpy.c
  )
endif ()