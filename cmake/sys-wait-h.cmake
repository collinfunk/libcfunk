
include_guard(GLOBAL)

# Generate <sys/wait.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_WAIT_H "1" CACHE INTERNAL "")

check_include_file("sys/wait.h" HAVE_SYS_WAIT_H)

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_WAITPID "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-wait-h.cmake)
endif ()

