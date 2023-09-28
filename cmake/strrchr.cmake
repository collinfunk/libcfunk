include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strrchr" "string.h" HAVE_STRRCHR)
else ()
  set(HAVE_STRRCHR "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRRCHR "1" CACHE INTERNAL "")

if (NOT HAVE_STRRCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strrchr.c
  )
endif ()