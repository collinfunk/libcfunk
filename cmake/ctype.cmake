
include_guard(GLOBAL)

check_include_file("ctype.h" HAVE_CTYPE_H)

set(LIBCFUNK_GENERATE_CTYPE_H TRUE)

check_symbol_exists(isalnum "ctype.h" HAVE_ISALNUM)
check_symbol_exists(isalpha "ctype.h" HAVE_ISALPHA)
check_symbol_exists(isascii "ctype.h" HAVE_ISASCII)
check_symbol_exists(isblank "ctype.h" HAVE_ISBLANK)
check_symbol_exists(iscntrl "ctype.h" HAVE_ISCNTRL)
check_symbol_exists(isdigit "ctype.h" HAVE_ISDIGIT)
check_symbol_exists(isgraph "ctype.h" HAVE_ISGRAPH)
check_symbol_exists(islower "ctype.h" HAVE_ISLOWER)
check_symbol_exists(isprint "ctype.h" HAVE_ISPRINT)
check_symbol_exists(ispunct "ctype.h" HAVE_ISPUNCT)
check_symbol_exists(isspace "ctype.h" HAVE_ISSPACE)
check_symbol_exists(isupper "ctype.h" HAVE_ISUPPER)
check_symbol_exists(isxdigit "ctype.h" HAVE_ISXDIGIT)
check_symbol_exists(toascii "ctype.h" HAVE_TOASCII)
check_symbol_exists(tolower "ctype.h" HAVE_TOLOWER)
check_symbol_exists(toupper "ctype.h" HAVE_TOUPPER)

# TODO: Should really write a macro to get rid of all these ugly lines.
# After checking symbols and headers, CMake sets the internal cache variable
# to an empty string. However, we need then to be 0 or 1 so they are replaced
# in the configure file.
if (NOT HAVE_CTYPE_H)
  set(HAVE_CTYPE_H 0)
endif ()

if (NOT ISALNUM)
  set(HAVE_ISALNUM 0)
endif ()

if (NOT ISALPHA)
  set(HAVE_ISALPHA 0)
endif ()

if (NOT ISASCII)
  set(HAVE_ISASCII 0)
endif ()

if (NOT ISBLANK)
  set(HAVE_ISBLANK 0)
endif ()

if (NOT ISCNTRL)
  set(HAVE_ISCNTRL 0)
endif ()

if (NOT ISDIGIT)
  set(HAVE_ISDIGIT 0)
endif ()

if (NOT ISGRAPH)
  set(HAVE_ISGRAPH 0)
endif ()

if (NOT ISLOWER)
  set(HAVE_ISLOWER 0)
endif ()

if (NOT ISPRINT)
  set(HAVE_ISPRINT 0)
endif ()

if (NOT ISPUNCT)
  set(HAVE_ISPUNCT 0)
endif ()

if (NOT ISSPACE)
  set(HAVE_ISSPACE 0)
endif ()

if (NOT ISUPPER)
  set(HAVE_ISUPPER 0)
endif ()

if (NOT ISXDIGIT)
  set(HAVE_ISXDIGIT 0)
endif ()

if (NOT TOASCII)
  set(HAVE_TOASCII 0)
endif ()

if (NOT TOLOWER)
  set(HAVE_TOLOWER 0)
endif ()

if (NOT TOUPPER)
  set(HAVE_TOUPPER 0)
endif ()
