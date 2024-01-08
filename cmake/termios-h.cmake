
include_guard(GLOBAL)

# Need struct winsize.
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-ioctl-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <termios.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_TERMIOS_H "1" CACHE STRING "")

check_include_file("termios.h" HAVE_TERMIOS_H)

if (HAVE_SYS_IOCTL_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/ioctl.h")
endif ()

if (HAVE_TERMIOS_H)
  find_file(TERMIOS_H_PATH NAMES "termios.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "termios.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

if (HAVE_TERMIOS_H)
  check_type_size("cc_t" CC_T)
  check_type_size("speed_t" SPEED_T)
  check_type_size("tcflag_t" TCFLAG_T)
  check_type_size("struct termios" STRUCT_TERMIOS)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-termios-h.cmake)
endif ()
