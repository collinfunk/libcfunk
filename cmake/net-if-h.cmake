
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

# Generate <net/if.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_NET_IF_H "1" CACHE STRING "")

check_include_file("net/if.h" HAVE_NET_IF_H)

# Check for 'struct if_nameindex'.
if (HAVE_NET_IF_H)
  find_file(NET_IF_H_PATH NAMES "net/if.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "net/if.h")
  check_type_size("struct if_nameindex" STRUCT_IF_NAMEINDEX)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-net-if-h.cmake)
endif ()

