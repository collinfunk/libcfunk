
include_guard(GLOBAL)

check_include_file("stdio.h" HAVE_STDIO_H)

if (HAVE_STDIO_H)
else ()
  set(HAVE_STDIO_H 0)
endif ()

