
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

# Generate <fcntl.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FCNTL_H "1" CACHE STRING "")

check_include_file("fcntl.h" HAVE_FCNTL_H)
check_include_file("io.h" HAVE_IO_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fcntl-h.cmake)
endif ()

