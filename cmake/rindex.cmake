
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

libcfunk_check_symbol_exists(rindex "strings.h" HAVE_RINDEX)

set(LIBCFUNK_DECLARE_RINDEX 1)

if (NOT HAVE_RINDEX)
  libcfunk_add_sources("rindex.c")
endif ()

