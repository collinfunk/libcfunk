
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <dirent.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_DIRENT_H "1" CACHE INTERNAL "")

check_include_file("dirent.h" HAVE_DIRENT_H)

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_ALPHASORT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_VERSIONSORT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_DIRFD "0" CACHE INTERNAL "")
