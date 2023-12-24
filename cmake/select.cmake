
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-select-h.cmake)

if (HAVE_SYS_SELECT_H OR HAVE_SYS_TIME_H OR HAVE_WINSOCK2_H)
  set(SELECT_INCLUDES "")
  if (HAVE_SYS_SELECT_H)
    list(APPEND SELECT_INCLUDES "sys/select.h")
  endif ()
  if (HAVE_SYS_TIME_H)
    list(APPEND SELECT_INCLUDES "sys/time.h")
  endif ()
  if (HAVE_WINSOCK2_H)
    list(APPEND SELECT_INCLUDES "winsock2.h")
  endif ()
  check_symbol_exists("select" "${SELECT_INCLUDES}" HAVE_SELECT)
  unset(SELECT_INCLUDES)
endif ()

# TODO
if (NOT HAVE_SELECT)
  message(FATAL_ERROR "No implementation of 'select' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

