
include_guard(GLOBAL)

# Generate <pty.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_PTY_H "1" CACHE INTERNAL "")

check_c_system_headers("pty.h")
