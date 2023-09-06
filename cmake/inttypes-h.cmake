
include_guard(GLOBAL)

# Generate <inttypes.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_INTTYPES_H "1" CACHE INTERNAL "")

check_include_file("inttypes.h" HAVE_INTTYPES_H)

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_STRTOIMAX "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRTOUMAX "0" CACHE INTERNAL "")
