
include_guard(GLOBAL)

# Generate <unistd.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UNISTD_H "1" CACHE INTERNAL "")

check_include_file("unistd.h" HAVE_UNISTD_H)

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_ENDUSERSHELL "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_GETCWD "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_GETPAGESIZE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_GETUSERSHELL "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SETUSERSHELL "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SWAB "0" CACHE INTERNAL "")
