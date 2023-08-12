
include_guard(GLOBAL)

check_include_file("stdint.h" HAVE_STDINT_H)

if (HAVE_STDINT_H)
else ()
  set(HAVE_STDINT_H 0)
endif ()

