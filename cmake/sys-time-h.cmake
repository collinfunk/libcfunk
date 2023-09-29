
include_guard(GLOBAL)

# Generate <sys/time.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TIME_H "1" CACHE INTERNAL "")

check_c_system_headers("sys/time.h")

