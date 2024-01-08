
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <alloca.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ALLOCA_H "1" CACHE STRING "")

check_include_file("alloca.h" HAVE_ALLOCA_H)

if (HAVE_ALLOCA_H)
  find_file(ALLOCA_H_PATH NAMES "alloca.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-alloca-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-alloca.cmake)
endif ()

