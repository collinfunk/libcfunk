
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strncat "string.h" HAVE_STRNCAT)

set(LIBCFUNK_DECLARE_STRNCAT 1)

if (NOT HAVE_STRNCAT)
  libcfunk_add_sources("strncat.c")
endif ()
