
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strspn "string.h" HAVE_STRSPN)

set(LIBCFUNK_DECLARE_STRSPN 1)

if (NOT HAVE_STRSPN)
  libcfunk_add_sources("strspn.c")
endif ()
