
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("explicit_bzero" "string.h" HAVE_EXPLICIT_BZERO)
endif ()

set(LIBCFUNK_DECLARE_EXPLICIT_BZERO "1" CACHE STRING "")

if (NOT HAVE_EXPLICIT_BZERO)
  check_symbol_exists("SecureZeroMemory" "windows.h" HAVE_SECUREZEROMEMORY)
  check_symbol_exists("memset_explicit" "string.h" HAVE_MEMSET_EXPLICIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/explicit_bzero.c
  )
endif ()
