
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_symbol_exists("posix_openpt" "stdlib.h" HAVE_POSIX_OPENPT)

# Linux, FreeBSD, MacOS, etc.
if (EXISTS "/dev/ptmx")
  set(HAVE_DEV_PTMX "1" CACHE INTERNAL "")
else ()
  set(HAVE_DEV_PTMX "" CACHE INTERNAL "")
endif ()

# AIX
if (EXISTS "/dev/ptc")
  set(HAVE_DEV_PTC "1" CACHE INTERNAL "")
else ()
  set(HAVE_DEV_PTC "" CACHE INTERNAL "")
endif ()

# OpenBSD.
if (EXISTS "/dev/ptm")
  set(HAVE_DEV_PTM "1" CACHE INTERNAL "")
else ()
  set(HAVE_DEV_PTM "" CACHE INTERNAL "")
endif ()

# OpenBSD.
check_include_file("sys/ioctl.h" HAVE_SYS_IOCTL_H)
if (HAVE_SYS_IOCTL_H)
  check_symbol_exists("ioctl" "sys/ioctl.h" HAVE_IOCTL)
else ()
  set(HAVE_IOCTL "" CACHE INTERNAL "")
endif ()

# OpenBSD.
check_include_file("sys/tty.h" HAVE_SYS_TTY_H)
if (HAVE_SYS_TTY_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/tty.h")
  check_type_size("struct ptmget" STRUCT_PTMGET)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "sys/tty.h")
else ()
  set(HAVE_STRUCT_PTMGET "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_POSIX_OPENPT "1" CACHE INTERNAL "")

if (NOT HAVE_POSIX_OPENPT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix-openpt.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix-openpt.cmake)
endif ()
