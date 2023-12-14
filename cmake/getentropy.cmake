
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-random-h.cmake)

if (HAVE_UNISTD_H OR HAVE_SYS_RANDOM_H)
  set(GETENTROPY_INCLUDES "")
  if (HAVE_UNISTD_H)
    list(APPEND GETENTROPY_INCLUDES "unistd.h")
  endif ()
  if (HAVE_SYS_RANDOM_H)
    list(APPEND GETENTROPY_INCLUDES "sys/random.h")
  endif ()
  check_symbol_exists("getentropy" "${GETRANDOM_INCLUDES}" HAVE_GETENTROPY)
  unset(GETENTROPY_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_GETENTROPY "1" CACHE STRING "")

if (NOT HAVE_GETENTROPY OR LIBCFUNK_REPLACE_GETENTROPY)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getentropy.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getentropy.cmake)
endif ()

