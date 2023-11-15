
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-ioctl-h.cmake)

set(IOCTL_INCLUDES "")
set(IOCTL_INCLUDE_SOURCE "")

if (HAVE_SYS_IOCTL_H OR HAVE_STROPTS_H OR HAVE_UNISTD_H)
  if (HAVE_SYS_IOCTL_H)
    list(APPEND IOCTL_INCLUDES "sys/ioctl.h")
    string(APPEND IOCTL_INCLUDE_SOURCE "#include <sys/ioctl.h>\n")
  endif ()
  if (HAVE_STROPTS_H)
    list(APPEND IOCTL_INCLUDES "stropts.h")
    string(APPEND IOCTL_INCLUDE_SOURCE "#include <stropts.h>\n")
  endif ()
  if (HAVE_UNISTD_H)
    list(APPEND IOCTL_INCLUDES "unistd.h")
    string(APPEND IOCTL_INCLUDE_SOURCE "#include <unistd.h>\n")
  endif ()
  check_symbol_exists("ioctl" "${IOCTL_INCLUDES}" HAVE_IOCTL)
  if (HAVE_IOCTL)
    check_c_source_compiles("
    ${IOCTL_INCLUDE_SOURCE}
    extern int ioctl (int, int, ...);
    int
    main (void)
    {
      return 0;
    }" IOCTL_HAS_POSIX_PROTOTYPE)
  endif ()
endif ()

unset(IOCTL_INCLUDES)
unset(IOCTL_INCLUDE_SOURCE)

if (HAVE_IOCTL)
  if (NOT IOCTL_HAS_POSIX_PROTOTYPE)
    set(LIBCFUNK_REPLACE_IOCTL "1" CACHE STRING "")
  endif ()
endif ()

set(LIBCFUNK_DECLARE_IOCTL "1" CACHE STRING "")

if (NOT HAVE_IOCTL OR LIBCFUNK_REPLACE_IOCTL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ioctl.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

