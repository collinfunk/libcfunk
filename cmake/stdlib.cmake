
include_guard(GLOBAL)

check_include_file("stdlib.h" HAVE_STDLIB_H)

if (HAVE_STDLIB_H)
else ()
  set(HAVE_STDLIB_H 0)
endif ()

