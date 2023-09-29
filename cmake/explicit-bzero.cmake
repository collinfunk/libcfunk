include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("explicit_bzero" "string.h")
check_c_symbol("SecureZeroMemory" "windows.h")
check_c_symbol("memset_explicit" "string.h")

set(LIBCFUNK_DECLARE_EXPLICIT_BZERO "1" CACHE INTERNAL "")

if (NOT HAVE_EXPLICIT_BZERO)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/explicit-bzero.c
  )
endif ()
