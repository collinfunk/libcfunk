
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

libcfunk_check_symbol_exists(index "strings.h" HAVE_INDEX)

set(LIBCFUNK_DECLARE_INDEX 1)

if (NOT HAVE_INDEX)
  libcfunk_add_sources("index.c")
endif ()

