
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)
include(${LIBCFUNK_MODULE_DIR}/strnlen.cmake)

libcfunk_check_symbol_exists(strndup "string.h" HAVE_STRNDUP)

set(LIBCFUNK_DECLARE_STRNDUP 1)

if (NOT HAVE_STRNDUP)
  libcfunk_add_sources("strndup.c")
endif ()

