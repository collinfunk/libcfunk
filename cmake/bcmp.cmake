
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

libcfunk_check_symbol_exists(bcmp "strings.h" HAVE_BCMP)

set(LIBCFUNK_DECLARE_BCMP 1)

if (NOT HAVE_BCMP)
  libcfunk_add_sources("bcmp.c")
endif ()

