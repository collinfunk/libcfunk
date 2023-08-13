
include_guard(GLOBAL)

check_include_file("stdio.h" HAVE_STDIO_H)

set(LIBCFUNK_GENERATE_STDIO_H TRUE)

if (HAVE_STDIO_H)
else ()
  set(HAVE_STDIO_H 0)
endif ()

