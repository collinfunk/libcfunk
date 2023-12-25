
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/utmp-h.cmake)

if (HAVE_UTMP_H OR HAVE_LIBUTIL_H OR HAVE_UTIL_H)
  set(LOGIN_TTY_INCLUDES "")
  if (HAVE_UTMP_H)
    list(APPEND LOGIN_TTY_INCLUDES "utmp.h")
  endif ()
  if (HAVE_LIBUTIL_H)
    list(APPEND LOGIN_TTY_INCLUDES "libutil.h")
  endif ()
  if (HAVE_UTIL_H)
    list(APPEND LOGIN_TTY_INCLUDES "util.h")
  endif ()
  check_symbol_exists("login_tty" "${LOGIN_TTY_INCLUDES}" HAVE_LOGIN_TTY_IN_LIBC)
  if (NOT HAVE_LOGIN_TTY_IN_LIBC)
    check_library_exists("util" "login_tty" "" HAVE_LOGIN_TTY_IN_LIBUTIL)
    if (HAVE_LOGIN_TTY_IN_LIBUTIL)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "util")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "util")
      list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
    endif ()
  endif ()
  if (HAVE_LOGIN_TTY_IN_LIBC OR HAVE_LOGIN_TTY_IN_LIBUTIL)
    set(HAVE_LOGIN_TTY "1" CACHE STRING "")
  endif ()
  unset(LOGIN_TTY_INCLUDES)
endif ()

# TODO
if (NOT HAVE_LOGIN_TTY)
  message(FATAL_ERROR "No implementation of 'login_tty' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

