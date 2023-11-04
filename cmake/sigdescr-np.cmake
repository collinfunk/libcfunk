
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("sigdescr_np" "string.h" HAVE_SIGDESCR_NP)
endif ()

set(LIBCFUNK_DECLARE_SIGDESCR_NP "1" CACHE INTERNAL "")

if (NOT HAVE_SIGDESCR_NP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sigdescr-np.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigdescr-np.cmake)
endif ()

