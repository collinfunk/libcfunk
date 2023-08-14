
include_guard(GLOBAL)

check_include_file("stdlib.h" HAVE_STDLIB_H)

set(LIBCFUNK_GENERATE_STDLIB_H TRUE)

set(LIBCFUNK_DECLARE_REALLOCARRAY 0)

if (HAVE_STDLIB_H)
else ()
  set(HAVE_STDLIB_H 0)
endif ()

