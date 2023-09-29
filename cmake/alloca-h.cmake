
include_guard(GLOBAL)

# Generate <alloca.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ALLOCA_H "1" CACHE INTERNAL "")

check_c_system_headers("alloca.h")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-alloca.cmake)
endif ()
