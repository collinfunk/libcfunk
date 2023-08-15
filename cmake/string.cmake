
include_guard(GLOBAL)

check_include_file("string.h" HAVE_STRING_H)

set(LIBCFUNK_GENERATE_STRING_H TRUE)

# Hide prototypes by default.
set(LIBCFUNK_DECLARE_STRCHRNUL 0)
set(LIBCFUNK_DECLARE_STRMODE 0)
set(LIBCFUNK_DECLARE_EXPLICIT_BZERO 0)
set(LIBCFUNK_DECLARE_STRDUP 0)
set(LIBCFUNK_DECLARE_STRNDUP 0)
set(LIBCFUNK_DECLARE_STRLEN 0)
set(LIBCFUNK_DECLARE_STRNLEN 0)
set(LIBCFUNK_DECLARE_STPCPY 0)
set(LIBCFUNK_DECLARE_STPNCPY 0)
set(LIBCFUNK_DECLARE_STRSEP 0)
set(LIBCFUNK_DECLARE_STRPBRK 0)

if (HAVE_STRING_H)
else ()
  set(HAVE_STRING_H 0)
endif ()

