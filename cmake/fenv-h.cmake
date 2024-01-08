
include_guard(GLOBAL)

# Generate <fenv.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FENV_H "1" CACHE STRING "")

check_include_file("fenv.h" HAVE_FENV_H)

if (HAVE_FENV_H)
  find_file(FENV_H_PATH NAMES "fenv.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "fenv.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("fenv_t" FENV_T)
  check_type_size("fexcept_t" FEXCEPT_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fenv-h.cmake)
endif ()

