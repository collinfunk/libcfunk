
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strcspn "string.h" HAVE_STRCSPN)

set(LIBCFUNK_DECLARE_STRCSPN 1)

if (NOT HAVE_STRCSPN)
  libcfunk_add_sources("stcspn.c")
endif ()
