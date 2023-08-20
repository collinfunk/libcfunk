
include_guard(GLOBAL)

check_include_file("unistd.h" HAVE_UNISTD_H)

set(LIBCFUNK_GENERATE_UNISTD_H TRUE)

# Hide prototypes by default.
set(LIBCFUNK_DECLARE_GETUSERSHELL 0)
set(LIBCFUNK_DECLARE_SETUSERSHELL 0)
set(LIBCFUNK_DECLARE_ENDUSERSHELL 0)

if (HAVE_UNISTD_H)
else ()
  set(HAVE_UNISTD_H 0)
endif ()

