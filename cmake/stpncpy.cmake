
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(stpncpy "string.h" HAVE_STPNCPY)

set(LIBCFUNK_DECLARE_STPNCPY 1)

if (NOT HAVE_STPNCPY)
  libcfunk_add_sources("stpncpy.c")
endif ()

