
include_guard(GLOBAL)

# Just incase winsize is defined in <termios.h> and not <sys/ioctl.h>.
include($CACHE{LIBCFUNK_MODULE_DIR}/termios-h.cmake)

# Generate <sys/ioctl.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_IOCTL_H "1" CACHE STRING "")

check_include_file("sys/types.h" HAVE_SYS_TYPES_H)
check_include_file("sys/ioctl.h" HAVE_SYS_IOCTL_H)

if (HAVE_SYS_IOCTL_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/ioctl.h")
endif ()

if (HAVE_TERMIOS_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "termios.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct winsize" STRUCT_WINSIZE)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-ioctl-h.cmake)
endif ()

