
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)
include(${LIBCFUNK_MODULE_DIR}/strlen.cmake)

libcfunk_check_symbol_exists(strdup "string.h" HAVE_STRDUP)

set(LIBCFUNK_DECLARE_STRDUP 1)

if (NOT HAVE_STRDUP)
  libcfunk_add_sources("strdup.c")
endif ()
