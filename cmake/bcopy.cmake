
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

libcfunk_check_symbol_exists(bcopy "strings.h" HAVE_BCOPY)

set(LIBCFUNK_DECLARE_BCOPY 1)

if (NOT HAVE_BCOPY)
  libcfunk_add_sources("bcopy.c")
endif ()

