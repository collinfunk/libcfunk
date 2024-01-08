
include_guard(GLOBAL)

# Generate <sysexits.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYSEXITS_H "1" CACHE STRING "")

check_include_file("sysexits.h" HAVE_SYSEXITS_H)

if (HAVE_SYSEXITS_H)
  find_file(SYSEXITS_H_PATH NAMES "sysexits.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sysexits-h.cmake)
endif ()

