
include_guard(GLOBAL)

# Generate <stdckdint.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDCKDINT_H "1" CACHE INTERNAL "")

check_c_system_headers("stdckdint")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdckdint.cmake)
endif ()
