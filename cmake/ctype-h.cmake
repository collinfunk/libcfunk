
include_guard(GLOBAL)

# Generate <ctype.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_CTYPE_H "1" CACHE INTERNAL "")

check_c_system_headers("ctype.h")

