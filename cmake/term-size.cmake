
include_guard(GLOBAL)

libcfunk_check_include_file("sys/ioctl.h" HAVE_SYS_IOCTL_H)
libcfunk_check_include_file("termios.h" HAVE_TERMIOS_H)

libcfunk_add_sources("term-size.h;term-size.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-term-size.cmake)
endif ()
