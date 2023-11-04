
include_guard(GLOBAL)

# Generate <sys/wait.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_WAIT_H "1" CACHE STRING "")

check_include_file("sys/wait.h" HAVE_SYS_WAIT_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-wait-h.cmake)
endif ()

