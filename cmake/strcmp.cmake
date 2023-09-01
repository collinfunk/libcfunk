
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strcmp "string.h" HAVE_STRCMP)

set(LIBCFUNK_DECLARE_STRCMP 1)

if (NOT HAVE_STRCMP)
  libcfunk_add_sources("strcmp.c")
endif ()
