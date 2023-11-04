
include_guard(GLOBAL)

# Generate <sys/endian.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_ENDIAN_H "1" CACHE STRING "")

check_include_file("sys/endian.h" HAVE_SYS_ENDIAN_H)
check_include_file("endian.h" HAVE_ENDIAN_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-endian-h.cmake)
endif ()
