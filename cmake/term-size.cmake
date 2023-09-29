
include_guard(GLOBAL)

check_c_system_headers("sys/ioctl.h")
check_c_system_headers("termios.h")

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/term-size.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/term-size.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-term-size.cmake)
endif ()

