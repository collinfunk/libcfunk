
include_guard(GLOBAL)

check_include_file("string.h" HAVE_STRING_H)

if (HAVE_STRING_H)
else ()
  set(HAVE_STRING_H 0)
endif ()

