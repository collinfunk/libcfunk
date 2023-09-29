include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strpbrk" "string.h")

set(LIBCFUNK_DECLARE_STRPBRK "1" CACHE INTERNAL "")

if (NOT HAVE_STRPBRK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strpbrk.c
  )
endif ()
