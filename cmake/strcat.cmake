
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strcat "string.h" HAVE_STRCAT)

set(LIBCFUNK_DECLARE_STRCAT 1)

if (NOT HAVE_STRCAT)
  libcfunk_add_sources("strcat.c")
endif ()
