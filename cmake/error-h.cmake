
include_guard(GLOBAL)

# Generate <error.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ERROR_H "1" CACHE INTERNAL "")

check_c_system_headers("error.h")

