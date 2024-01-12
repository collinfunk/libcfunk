
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/net-if-h.cmake)

if (HAVE_NET_IF_H)
  check_symbol_exists("if_indextoname" "net/if.h" HAVE_IF_INDEXTONAME)
endif ()

# TODO: Windows implementation. See 'netif.h.in' for comments.
if (NOT HAVE_IF_INDEXTONAME)
  message(FATAL_ERROR "No implementation of 'if_indextoname' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-if_indextoname.cmake)
endif ()

