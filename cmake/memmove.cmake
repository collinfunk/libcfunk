
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(memmove "string.h" HAVE_MEMMOVE)

set(LIBCFUNK_DECLARE_MEMMOVE 1)

if (NOT HAVE_MEMMOVE)
  libcfunk_add_sources("memmove.c")
endif ()
