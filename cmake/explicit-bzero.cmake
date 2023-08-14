
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(explicit_bzero "string.h" HAVE_EXPLICIT_BZERO)
check_symbol_exists(memset_explicit "string.h" HAVE_MEMSET_EXPLICIT)
check_symbol_exists(SecureZeroMemory "windows.h" HAVE_SECUREZEROMEMORY)

set(LIBCFUNK_DECLARE_EXPLICIT_BZERO 1)

if (NOT HAVE_EXPLICIT_BZERO)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/explicit-bzero.c
  )
endif ()

