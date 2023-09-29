
include_guard(GLOBAL)

# Generate <stdio.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDIO_H "1" CACHE INTERNAL "")

check_c_system_headers("stdio.h")

# Don't declare functions we don't check.
set(LIBCFUNK_DECLARE_GETDELIM "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_GETLINE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FSEEKO "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FTELLO "0" CACHE INTERNAL "")

# Use compatiblity macros for getc_unlocked and friends on Windows.
# See unlocked-stdio.cmake
set(LIBCFUNK_UNLOCKED_STDIO "0" CACHE INTERNAL "")
