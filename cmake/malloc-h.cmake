
include_guard(GLOBAL)

# Generate <malloc.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_MALLOC_H "1" CACHE INTERNAL "")

check_c_system_headers("malloc.h")

