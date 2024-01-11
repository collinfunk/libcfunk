
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/alloca-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("execle" "unistd.h" HAVE_EXECLE)
  check_symbol_exists("execve" "unistd.h" HAVE_EXECVE)
endif ()

set(LIBCFUNK_DECLARE_EXECLE "1" CACHE STRING "")

if (NOT HAVE_EXECLE)
  # FIXME
  if (NOT HAVE_EXECVE)
    message(FATAL_ERROR "No implementation is avaiable for `execve'.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execle.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-execle.cmake)
endif ()

