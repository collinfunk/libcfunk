
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/net-if-h.cmake)

if (HAVE_NET_IF_H)
  check_symbol_exists("if_nameindex" "net/if.h" HAVE_IF_NAMEINDEX)
endif ()

# TODO: Windows implementation. See 'netif.h.in' for comments.
if (NOT HAVE_IF_NAMEINDEX)
  message(FATAL_ERROR "No implementation of 'if_nameindex' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-if_nameindex.cmake)
endif ()

