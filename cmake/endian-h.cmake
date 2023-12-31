
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/byteswap-h.cmake)

set(LIBCFUNK_GENERATE_ENDIAN_H "1" CACHE STRING "")

# Check for <endian.h> and <sys/endian.h>
check_include_file("endian.h" HAVE_ENDIAN_H)
check_include_file("sys/endian.h" HAVE_SYS_ENDIAN_H)

if (HAVE_ENDIAN_H)
  find_file(ENDIAN_H_PATH NAMES "endian.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-endian-h.cmake)
endif ()

