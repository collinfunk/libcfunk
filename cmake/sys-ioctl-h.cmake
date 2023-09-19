
include_guard(GLOBAL)

# Just incase winsize is defined in <termios.h> and not <sys/ioctl.h>.
include($CACHE{LIBCFUNK_MODULE_DIR}/termios-h.cmake)

# Generate <sys/ioctl.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_IOCTL_H "1" CACHE INTERNAL "")

check_include_file("sys/ioctl.h" HAVE_SYS_IOCTL_H)

# Check for struct winsize in sys/types.h, termios.h, and sys/ioctl.h.
set(WINSIZE_CHECK "#include <sys/types.h>\n")
if (HAVE_SYS_IOCTL_H)
  string(APPEND WINSIZE_CHECK "#include <sys/ioctl.h>\n")
endif ()

if (HAVE_TERMIOS_H)
  string(APPEND WINSIZE_CHECK "#include <termios.h>\n")
endif ()

string(APPEND WINSIZE_CHECK "
int
main (void)
{
  struct winsize ws;
  return 0;
}")

check_c_source_compiles("${WINSIZE_CHECK}" HAVE_STRUCT_WINSIZE)

unset(WINSIZE_CHECK)

if (HAVE_STRUCT_WINSIZE)
  set(HAVE_STRUCT_WINSIZE "1" CACHE INTERNAL "")
else ()
  set(HAVE_STRUCT_WINSIZE "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-ioctl-h.cmake)
endif ()
