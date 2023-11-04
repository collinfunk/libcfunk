
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strerrordesc_np" "string.h" HAVE_STRERRORDESC_NP)
endif ()

set(LIBCFUNK_DECLARE_STRERRORDESC_NP "1" CACHE INTERNAL "")

if (NOT HAVE_STRERRORDESC_NP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strerrordesc-np.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strerrordesc-np.cmake)
endif ()
