
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/byteswap-h.cmake)

# Check for <endian.h>
check_include_file("endian.h" HAVE_ENDIAN_H)

set(LIBCFUNK_GENERATE_ENDIAN_H "1" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-endian-h.cmake)
endif ()

