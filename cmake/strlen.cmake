
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strlen "string.h" HAVE_STRLEN)

set(LIBCFUNK_DECLARE_STRLEN 1)

if (NOT HAVE_STRLEN)
  libcfunk_add_sources("stplen.c")
endif ()
