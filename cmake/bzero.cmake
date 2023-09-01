
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

libcfunk_check_symbol_exists(bzero "strings.h" HAVE_BZERO)

set(LIBCFUNK_DECLARE_BZERO 1)

if (NOT HAVE_BZERO)
  libcfunk_add_sources("bzero.c")
endif ()

