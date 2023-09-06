
include_guard(GLOBAL)

check_include_file("sys/ioctl.h" HAVE_SYS_IOCTL_H)
check_include_file("termios.h" HAVE_TERMIOS_H)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/term-size.c
  ${LIBCFUNK_SOURCE_DIR}/term-size.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-term-size.cmake)
endif ()

