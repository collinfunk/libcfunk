
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdio.cmake)
include(${LIBCFUNK_MODULE_DIR}/getdelim.cmake)

libcfunk_check_symbol_exists(getline "stdio.h" HAVE_GETLINE)

set(LIBCFUNK_DECLARE_GETLINE 1)

if (NOT HAVE_GETLINE)
  libcfunk_add_sources("getline.c")
endif ()

