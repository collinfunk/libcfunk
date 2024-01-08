
include_guard(GLOBAL)

# Generate <stdckdint.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDCKDINT_H "1" CACHE STRING "")

check_include_file("stdckdint.h" HAVE_STDCKDINT_H)

if (HAVE_STDCKDINT_H)
  find_file(STDCKDINT_H_PATH NAMES "stdckdint.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdckdint.cmake)
endif ()
