
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-ioctl-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/termios-h.cmake)

# Generate <pty.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_PTY_H "1" CACHE STRING "")

check_include_file("pty.h" HAVE_PTY_H)
check_include_file("libutil.h" HAVE_LIBUTIL_H)
check_include_file("util.h" HAVE_UTIL_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-pty-h.cmake)
endif ()

