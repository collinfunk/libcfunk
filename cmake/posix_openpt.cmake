
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_symbol_exists("posix_openpt" "stdlib.h" HAVE_POSIX_OPENPT)

set(LIBCFUNK_DECLARE_POSIX_OPENPT "1" CACHE STRING "")

if (NOT HAVE_POSIX_OPENPT)
  # Linux, FreeBSD, MacOS, etc.
  if (EXISTS "/dev/ptmx" AND NOT CMAKE_CROSSCOMPILING)
    set(HAVE_DEV_PTMX "1" CACHE STRING "")
  else ()
    set(HAVE_DEV_PTMX "" CACHE STRING "")
  endif ()
  # AIX
  if (EXISTS "/dev/ptc" AND NOT CMAKE_CROSSCOMPILING)
    set(HAVE_DEV_PTC "1" CACHE STRING "")
  else ()
    set(HAVE_DEV_PTC "" CACHE STRING "")
  endif ()
  # OpenBSD.
  if (EXISTS "/dev/ptm" AND NOT CMAKE_CROSSCOMPILING)
    set(HAVE_DEV_PTM "1" CACHE STRING "")
  else ()
    set(HAVE_DEV_PTM "" CACHE STRING "")
  endif ()
  # OpenBSD.
  check_include_file("sys/ioctl.h" HAVE_SYS_IOCTL_H)
  if (HAVE_SYS_IOCTL_H)
    check_symbol_exists("ioctl" "sys/ioctl.h" HAVE_IOCTL)
  else ()
    set(HAVE_IOCTL "" CACHE STRING "")
  endif ()
  # OpenBSD.
  check_include_file("sys/tty.h" HAVE_SYS_TTY_H)
  if (HAVE_SYS_TTY_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/tty.h")
    check_type_size("struct ptmget" STRUCT_PTMGET)
    list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "sys/tty.h")
  else ()
    set(HAVE_STRUCT_PTMGET "" CACHE STRING "")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_openpt.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_openpt.cmake)
endif ()
