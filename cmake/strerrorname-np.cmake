include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strerrorname_np" "string.h" HAVE_STRERRORNAME_NP)
else ()
  set(HAVE_STRERRORNAME_NP "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRERRORNAME_NP "1" CACHE INTERNAL "")

if (NOT HAVE_STRERRORNAME_NP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strerrorname-np.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strerrorname-np.cmake)
endif ()
