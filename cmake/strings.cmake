
include_guard(GLOBAL)

check_include_file("strings.h" HAVE_STRINGS_H)

if (HAVE_STRINGS_H)
else ()
  set(HAVE_STRINGS_H 0)
endif ()

