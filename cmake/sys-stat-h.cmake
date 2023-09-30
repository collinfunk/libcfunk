
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/stat.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_STAT_H "1" CACHE INTERNAL "")

check_include_file("sys/stat.h" HAVE_SYS_STAT_H)

set(LIBCFUNK_DECLARE_CHMOD "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MKDIR "0" CACHE INTERNAL "")


