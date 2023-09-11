include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strchrnul" "string.h" HAVE_STRCHRNUL)
else ()
  set(HAVE_STRCHRNUL "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRCHRNUL "1" CACHE INTERNAL "")

if (NOT HAVE_STRCHRNUL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strchrnul.c
  )
endif ()