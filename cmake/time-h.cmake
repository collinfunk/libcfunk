
include_guard(GLOBAL)

# Generate <time.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_TIME_H "1" CACHE INTERNAL "")

check_c_system_headers("time.h")

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_DYSIZE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_TIMESPEC_GET "0" CACHE INTERNAL "")

