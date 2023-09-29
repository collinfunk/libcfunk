
include_guard(GLOBAL)

# Generate <dirent.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_DIRENT_H "1" CACHE INTERNAL "")

check_c_system_headers("dirent.h")

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_ALPHASORT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_VERSIONSORT "0" CACHE INTERNAL "")
