include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strchrnul" "string.h")

set(LIBCFUNK_DECLARE_STRCHRNUL "1" CACHE INTERNAL "")

if (NOT HAVE_STRCHRNUL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strchrnul.c
  )
endif ()
