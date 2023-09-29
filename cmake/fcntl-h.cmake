
include_guard(GLOBAL)

# Generate <fcntl.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FCNTL_H "1" CACHE INTERNAL "")

check_c_system_headers("fcntl.h")

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_CREAT "0" CACHE INTERNAL "")
