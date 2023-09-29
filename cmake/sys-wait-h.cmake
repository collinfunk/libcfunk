
include_guard(GLOBAL)

# Generate <sys/wait.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_WAIT_H "1" CACHE INTERNAL "")

check_c_system_headers("sys/wait.h")

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_WAITPID "0" CACHE INTERNAL "")

