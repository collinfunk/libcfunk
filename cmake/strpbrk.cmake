
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strpbrk "string.h" HAVE_STRPBRK)

set(LIBCFUNK_DECLARE_STRPBRK 1)

if (NOT HAVE_STRPBRK)
  libcfunk_add_sources("strpbrk.c")
endif ()
