
include_guard(GLOBAL)

# Need struct winsize.
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-ioctl-h.cmake)

# Generate <termios.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_TERMIOS_H "1" CACHE INTERNAL "")

check_include_file("sys/types.h" HAVE_SYS_TYPES_H)
check_include_file("termios.h" HAVE_TERMIOS_H)

if (HAVE_SYS_TYPES_H)
  list(APPEND TERMIOS_INCLUDES "sys/types.h")
endif ()

if (HAVE_SYS_IOCTL_H)
  list(APPEND TERMIOS_INCLUDES "sys/ioctl.h")
endif ()

if (HAVE_TERMIOS_H)
  list(APPEND TERMIOS_INCLUDES "termios.h")
endif ()

foreach (header ${TERMIOS_INCLUDES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "${header}")
endforeach ()

check_type_size("struct termios" STRUCT_TERMIOS)

foreach (header ${TERMIOS_INCLUDES})
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "${header}")
endforeach ()

unset(TERMIOS_INCLUDES)

set(LIBCFUNK_DECLARE_TCGETSID "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-termios-h.cmake)
endif ()
