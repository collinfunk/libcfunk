include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memchr" "string.h" HAVE_MEMCHR)
else ()
  set(HAVE_MEMCHR "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_MEMCHR "1" CACHE INTERNAL "")

if (NOT HAVE_MEMCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memchr.c
  )
endif ()