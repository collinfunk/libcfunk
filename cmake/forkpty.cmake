
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/pty-h.cmake)

if (HAVE_PTY_H OR HAVE_LIBUTIL_H OR HAVE_UTIL_H)
  set(FORKPTY_INCLUDES "")
  if (HAVE_PTY_H)
    list(APPEND FORKPTY_INCLUDES "pty.h")
  endif ()
  if (HAVE_LIBUTIL_H)
    list(APPEND FORKPTY_INCLUDES "libutil.h")
  endif ()
  if (HAVE_UTIL_H)
    list(APPEND FORKPTY_INCLUDES "util.h")
  endif ()
  check_symbol_exists("forkpty" "${FORKPTY_INCLUDES}" HAVE_FORKPTY)
  if (NOT HAVE_FORKPTY)
    check_library_exists("util" "forkpty" "" HAVE_LIBUTIL)
    if (HAVE_LIBUTIL)
      set(HAVE_FORKPTY "1" CACHE INTERNAL "")
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "util")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "util")
    endif ()
  endif ()
  if (HAVE_FORKPTY)
    set(FORKPTY_INCLUDE_SOURCE "")
    foreach (header ${FORKPTY_INCLUDES})
      list(APPEND FORKPTY_INCLUDE_SOURCE "#include <${header}>\n")
    endforeach ()
    check_c_source_compiles("
    ${FORKPTY_INCLUDE_SOURCE}
    extern pid_t forkpty (int *, char *, const struct termios *,
                          const struct winsize *);
    int
    main (void)
    {
      return 0;
    }
    " FORKPTY_HAS_CONST_PROTOTYPE)
    if (NOT FORKPTY_HAS_CONST_PROTOTYPE)
      set(LIBCFUNK_REPLACE_FORKPTY "1" CACHE STRING "")
    endif ()
    unset(FORKPTY_INCLUDE_SOURCE)
  endif ()
  unset(FORKPTY_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_FORKPTY "1" CACHE STRING "")

if (NOT HAVE_FORKPTY OR LIBCFUNK_REPLACE_FORKPTY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/forkpty.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-forkpty.cmake)
endif ()

