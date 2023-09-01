
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(explicit_bzero "string.h" HAVE_EXPLICIT_BZERO)
libcfunk_check_symbol_exists(memset_explicit "string.h" HAVE_MEMSET_EXPLICIT)
libcfunk_check_symbol_exists(SecureZeroMemory "windows.h" HAVE_SECUREZEROMEMORY)

set(LIBCFUNK_DECLARE_EXPLICIT_BZERO 1)

if (NOT HAVE_EXPLICIT_BZERO)
  libcfunk_add_sources("explicit-bzero.c")
endif ()

