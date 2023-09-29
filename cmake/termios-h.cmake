
include_guard(GLOBAL)

# Need struct winsize.
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-ioctl-h.cmake)

# Generate <termios.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_TERMIOS_H "1" CACHE INTERNAL "")

check_c_system_headers("termios.h")

# check_c_type_exists won't work for this.
if (HAVE_TERMIOS_H)
  check_c_compiles("
  #include <sys/types.h>
  #include <termios.h>

  int
  main (void)
  {
    struct termios check_termios;
    return 0;
  }" HAVE_STRUCT_TERMIOS)

  if (HAVE_STRUCT_TERMIOS)
    set(HAVE_STRUCT_TERMIOS "1" CACHE INTERNAL "")
  else ()
    set(HAVE_STRUCT_TERMIOS "" CACHE INTERNAL "")
  endif ()
else ()
  set(HAVE_STRUCT_TERMIOS "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-termios-h.cmake)
endif ()
