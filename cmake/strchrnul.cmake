
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strchrnul "string.h" HAVE_STRCHRNUL)

set(LIBCFUNK_DECLARE_STRCHRNUL 1)

if (NOT HAVE_STRCHRNUL)
  libcfunk_add_sources("strchrnul.c")
endif ()

