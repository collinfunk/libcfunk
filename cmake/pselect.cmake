
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-select-h.cmake)

if (HAVE_SYS_SELECT_H OR HAVE_SYS_TIME_H OR HAVE_WINSOCK2_H)
  set(PSELECT_INCLUDES "")
  if (HAVE_SYS_SELECT_H)
    list(APPEND PSELECT_INCLUDES "sys/select.h")
  endif ()
  if (HAVE_SYS_TIME_H)
    list(APPEND PSELECT_INCLUDES "sys/time.h")
  endif ()
  if (HAVE_WINSOCK2_H)
    list(APPEND PSELECT_INCLUDES "winsock2.h")
  endif ()
  check_symbol_exists("pselect" "${PSELECT_INCLUDES}" HAVE_PSELECT)
  unset(PSELECT_INCLUDES)
endif ()

# TODO
if (NOT HAVE_PSELECT)
  message(FATAL_ERROR "No implementation of 'pselect' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

