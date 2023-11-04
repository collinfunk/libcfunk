
include_guard(GLOBAL)

# Generate <sys/random.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_RANDOM_H "1" CACHE STRING "")

check_include_file("sys/random.h" HAVE_SYS_RANDOM_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-random-h.cmake)
endif ()

