
include_guard(GLOBAL)

# Generate <err.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ERR_H "1" CACHE INTERNAL "")

check_include_file("err.h" HAVE_ERR_H)
