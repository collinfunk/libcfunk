
include_guard(GLOBAL)

# Generate <sys/endian.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_ENDIAN_H "1" CACHE INTERNAL "")

check_c_system_headers("sys/endian.h")
check_c_system_headers("endian.h")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-endian-h.cmake)
endif ()
