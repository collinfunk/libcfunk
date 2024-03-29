
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/alloca-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/execvp.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("execlp" "unistd.h" HAVE_EXECLP)
endif ()

set(LIBCFUNK_DECLARE_EXECLP "1" CACHE STRING "")

if (NOT HAVE_EXECLP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execlp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-execlp.cmake)
endif ()

