include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strspn" "string.h" HAVE_STRSPN)
else ()
  set(HAVE_STRSPN "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRSPN "1" CACHE INTERNAL "")

if (NOT HAVE_STRSPN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strspn.c
  )
endif ()