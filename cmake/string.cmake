
include_guard(GLOBAL)

check_include_file("string.h" HAVE_STRING_H)

set(LIBCFUNK_GENERATE_STRING_H TRUE)

if (HAVE_STRING_H)
else ()
  set(HAVE_STRING_H 0)
endif ()

