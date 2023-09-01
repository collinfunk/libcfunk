
include_guard(GLOBAL)

libcfunk_check_include_file("stdint.h" HAVE_STDINT_H)

set(LIBCFUNK_GENERATE_STDINT_H TRUE)
set(SIZEOF_VOID_P ${CMAKE_SIZEOF_VOID_P})
