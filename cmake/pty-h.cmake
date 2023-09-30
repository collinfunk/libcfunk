
include_guard(GLOBAL)

# Generate <pty.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_PTY_H "1" CACHE INTERNAL "")

check_include_file("pty.h" HAVE_PTY_H)
