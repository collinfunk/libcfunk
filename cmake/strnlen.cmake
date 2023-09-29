include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strnlen" "string.h")

set(LIBCFUNK_DECLARE_STRNLEN "1" CACHE INTERNAL "")

if (NOT HAVE_STRNLEN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strnlen.c
  )
endif ()
