
include_guard(GLOBAL)

# Generate <netinet/in.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_NETINET_IN_H "1" CACHE INTERNAL "")

check_include_file("netinet/in.h" HAVE_NETINET_IN_H)
