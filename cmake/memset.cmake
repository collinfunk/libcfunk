include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memset" "string.h" HAVE_MEMSET)
else ()
  set(HAVE_MEMSET "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_MEMSET "1" CACHE INTERNAL "")

if (NOT HAVE_MEMSET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memset.c
  )
endif ()