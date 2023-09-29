
include_guard(GLOBAL)

# Generate <sys/random.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_RANDOM_H "1" CACHE INTERNAL "")

check_c_system_headers("sys/random.h")

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_GETENTROPY "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_GETRANDOM "0" CACHE INTERNAL "")

