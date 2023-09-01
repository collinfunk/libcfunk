
include_guard(GLOBAL)

libcfunk_check_include_file("ctype.h" HAVE_CTYPE_H)

set(LIBCFUNK_GENERATE_CTYPE_H TRUE)

libcfunk_check_symbol_exists(isalnum "ctype.h" HAVE_ISALNUM)
libcfunk_check_symbol_exists(isalpha "ctype.h" HAVE_ISALPHA)
libcfunk_check_symbol_exists(isascii "ctype.h" HAVE_ISASCII)
libcfunk_check_symbol_exists(isblank "ctype.h" HAVE_ISBLANK)
libcfunk_check_symbol_exists(iscntrl "ctype.h" HAVE_ISCNTRL)
libcfunk_check_symbol_exists(isdigit "ctype.h" HAVE_ISDIGIT)
libcfunk_check_symbol_exists(isgraph "ctype.h" HAVE_ISGRAPH)
libcfunk_check_symbol_exists(islower "ctype.h" HAVE_ISLOWER)
libcfunk_check_symbol_exists(isprint "ctype.h" HAVE_ISPRINT)
libcfunk_check_symbol_exists(ispunct "ctype.h" HAVE_ISPUNCT)
libcfunk_check_symbol_exists(isspace "ctype.h" HAVE_ISSPACE)
libcfunk_check_symbol_exists(isupper "ctype.h" HAVE_ISUPPER)
libcfunk_check_symbol_exists(isxdigit "ctype.h" HAVE_ISXDIGIT)
libcfunk_check_symbol_exists(toascii "ctype.h" HAVE_TOASCII)
libcfunk_check_symbol_exists(tolower "ctype.h" HAVE_TOLOWER)
libcfunk_check_symbol_exists(toupper "ctype.h" HAVE_TOUPPER)

if (NOT HAVE_ISALNUM)
  libcfunk_add_sources("isalnum.c")
endif ()

if (NOT HAVE_ISALPHA)
  libcfunk_add_sources("isalpha.c")
endif ()

if (NOT HAVE_ISASCII)
  libcfunk_add_sources("isascii.c")
endif ()

if (NOT HAVE_ISBLANK)
  libcfunk_add_sources("isblank.c")
endif ()

if (NOT HAVE_ISCNTRL)
  libcfunk_add_sources("iscntrl.c")
endif ()

if (NOT HAVE_ISDIGIT)
  libcfunk_add_sources("isdigit.c")
endif ()

if (NOT HAVE_ISGRAPH)
  libcfunk_add_sources("isgraph.c")
endif ()

if (NOT HAVE_ISLOWER)
  libcfunk_add_sources("islower.c")
endif ()

if (NOT HAVE_ISPRINT)
  libcfunk_add_sources("isprint.c")
endif ()

if (NOT HAVE_ISPUNCT)
  libcfunk_add_sources("ispunct.c")
endif ()

if (NOT HAVE_ISSPACE)
  libcfunk_add_sources("isspace.c")
endif ()

if (NOT HAVE_ISUPPER)
  libcfunk_add_sources("isupper.c")
endif ()

if (NOT HAVE_ISXDIGIT)
  libcfunk_add_sources("isxdigit.c")
endif ()

if (NOT HAVE_TOASCII)
  libcfunk_add_sources("toascii.c")
endif ()

if (NOT HAVE_TOLOWER)
  libcfunk_add_sources("tolower.c")
endif ()

if (NOT HAVE_TOUPPER)
  libcfunk_add_sources("toupper.c")
endif ()
