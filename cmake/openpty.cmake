
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/pty-h.cmake)

if (HAVE_PTY_H OR HAVE_LIBUTIL_H OR HAVE_UTIL_H)
  set(OPENPTY_INCLUDES "")
  if (HAVE_PTY_H)
    list(APPEND OPENPTY_INCLUDES "pty.h")
  endif ()
  if (HAVE_LIBUTIL_H)
    list(APPEND OPENPTY_INCLUDES "libutil.h")
  endif ()
  if (HAVE_UTIL_H)
    list(APPEND OPENPTY_INCLUDES "util.h")
  endif ()
  check_symbol_exists("openpty" "${OPENPTY_INCLUDES}" HAVE_OPENPTY_IN_LIBC)
  if (NOT HAVE_OPENPTY_IN_LIBC)
    check_library_exists("util" "openpty" "" HAVE_OPENPTY_IN_LIBUTIL)
    if (HAVE_OPENPTY_IN_LIBUTIL)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "util")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "util")
      list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
    endif ()
  endif ()
  if (HAVE_OPENPTY_IN_LIBC OR HAVE_OPENPTY_IN_LIBUTIL)
    set(HAVE_OPENPTY "1" CACHE STRING "")
  endif ()
  if (HAVE_OPENPTY)
    set(OPENPTY_INCLUDE_SOURCE "")
    foreach (header ${OPENPTY_INCLUDES})
      list(APPEND OPENPTY_INCLUDE_SOURCE "#include <${header}>\n")
    endforeach ()
    check_c_source_compiles("
    ${OPENPTY_INCLUDE_SOURCE}
    extern int openpty (int *, int *, char *, const struct termios *,
                        const struct winsize *);
    int
    main (void)
    {
      return 0;
    }
    " OPENPTY_HAS_CONST_PROTOTYPE)
    if (NOT OPENPTY_HAS_CONST_PROTOTYPE)
      set(LIBCFUNK_REPLACE_OPENPTY "1" CACHE STRING "")
    endif ()
    unset(OPENPTY_INCLUDE_SOURCE)
  endif ()
  unset(OPENPTY_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_OPENPTY "1" CACHE STRING "")

if (NOT HAVE_OPENPTY OR LIBCFUNK_REPLACE_OPENPTY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/openpty.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-openpty.cmake)
endif ()

