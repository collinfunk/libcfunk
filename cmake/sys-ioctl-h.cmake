
include_guard(GLOBAL)

# Just incase winsize is defined in <termios.h> and not <sys/ioctl.h>.
include($CACHE{LIBCFUNK_MODULE_DIR}/termios-h.cmake)

# Generate <sys/ioctl.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_IOCTL_H "1" CACHE INTERNAL "")

check_include_file("sys/types.h" HAVE_SYS_TYPES_H)
check_include_file("sys/ioctl.h" HAVE_SYS_IOCTL_H)

# Check for struct winsize in sys/types.h, termios.h, and sys/ioctl.h.
set(WINSIZE_INCLUDES "")

if (HAVE_SYS_TYPES_H)
  list(APPEND WINSIZE_INCLUDES "sys/types.h")
endif ()

if (HAVE_SYS_IOCTL_H)
  list(APPEND WINSIZE_INCLUDES "sys/ioctl.h")
endif ()

if (HAVE_TERMIOS_H)
  list(APPEND WINSIZE_INCLUDES "termios.h")
endif ()

foreach (header ${WINSIZE_INCLUDES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "${header}")
endforeach ()

check_type_size("struct winsize" STRUCT_WINSIZE)

foreach (header ${WINSIZE_INCLUDES})
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "${header}")
endforeach ()

unset(WINSIZE_INCLUDES)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-ioctl-h.cmake)
endif ()

