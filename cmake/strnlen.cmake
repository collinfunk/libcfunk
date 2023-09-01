
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strnlen "string.h" HAVE_STRNLEN)

set(LIBCFUNK_DECLARE_STRNLEN 1)

if (NOT HAVE_STRNLEN)
  libcfunk_add_sources("strnlen.c")
endif ()

