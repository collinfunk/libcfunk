
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/execvpe.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("execvp" "unistd.h" HAVE_EXECVP)
endif ()

set(LIBCFUNK_DECLARE_EXECVP "1" CACHE STRING "")

if (NOT HAVE_EXECVP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execvp.c
  )
endif ()

