
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/alloca-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("execle" "unistd.h" HAVE_EXECLE)
  check_symbol_exists("execve" "unistd.h" HAVE_EXECVE)
else ()
  set(HAVE_EXECLE "" CACHE INTERAL "")
  set(HAVE_EXECVE "" CACHE INTERAL "")
endif ()

set(LIBCFUNK_DECLARE_EXECLE "1" CACHE INTERNAL "")

if (NOT HAVE_EXECLE)
  # FIXME
  if (NOT HAVE_EXECVE)
    message(FATAL_ERROR "No implementation is avaiable for `execve'.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execle.c
  )
endif ()
