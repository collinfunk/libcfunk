
include_guard(GLOBAL)

check_include_file("stdint.h" HAVE_STDINT_H)

set(LIBCFUNK_GENERATE_STDINT_H TRUE)

if (HAVE_STDINT_H)
else ()
  set(HAVE_STDINT_H 0)
endif ()

