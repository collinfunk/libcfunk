
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("sigabbrev_np" "string.h" HAVE_SIGABBREV_NP)
endif ()

set(LIBCFUNK_DECLARE_SIGABBREV_NP "1" CACHE INTERNAL "")

if (NOT HAVE_SIGABBREV_NP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sigabbrev-np.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigabbrev-np.cmake)
endif ()

