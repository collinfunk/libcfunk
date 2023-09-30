
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_symbol_exists("_Exit" "stdlib.h" HAVE_C99__EXIT)
check_symbol_exists("_exit" "unistd.h" HAVE__EXIT)

set(LIBCFUNK_DECLARE_C99__EXIT "1" CACHE INTERNAL "")

if (NOT HAVE_C99__EXIT)
  if (NOT HAVE__EXIT)
    message(FATAL_ERROR "Your system does not have C99's _Exit () and does \
not have POSIX's _exit () to act as a substitute for it. \
See ${LIBCFUNK_SOURCE_DIR}/_Exit.c for more details.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/_Exit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-_Exit.cmake)
endif ()
