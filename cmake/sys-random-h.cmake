
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/random.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_RANDOM_H "1" CACHE STRING "")

check_include_file("sys/random.h" HAVE_SYS_RANDOM_H)
check_include_file("unistd.h" HAVE_UNISTD_H)

if (HAVE_SYS_RANDOM_H)
  find_file(SYS_RANDOM_H_PATH NAMES "sys/random.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-random-h.cmake)
endif ()

