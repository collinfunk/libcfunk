
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strrchr "string.h" HAVE_STRRCHR)

set(LIBCFUNK_DECLARE_STRRCHR 1)

if (NOT HAVE_STRRCHR)
  libcfunk_add_sources("strrchr.c")
endif ()
