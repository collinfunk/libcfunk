
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

# Generate <sys/select.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_SELECT_H "1" CACHE STRING "")

check_include_file("sys/select.h" HAVE_SYS_SELECT_H)
check_include_file("sys/time.h" HAVE_SYS_TIME_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-select-h.cmake)
endif ()

