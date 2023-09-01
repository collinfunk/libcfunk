
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

libcfunk_check_symbol_exists(reallocarray "stdlib.h" HAVE_REALLOCARRAY)

set(LIBCFUNK_DECLARE_REALLOCARRAY 1)

if (NOT HAVE_REALLOCARRAY)
  libcfunk_add_sources("reallocarray.c")
endif()

