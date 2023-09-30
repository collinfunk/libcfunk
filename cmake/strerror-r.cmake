include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strerror_r" "string.h" HAVE_STRERROR_R)
  check_symbol_exists("strerror_s" "string.h" HAVE_STRERROR_S)
  # GNU libc hides this pretty well in string.h, just check we can link.
  check_function_exists("__xpg_strerror_r" HAVE___XPG_STRERROR_R)
else ()
  set(HAVE_STRERROR_R "" CACHE INTERNAL "")
  set(HAVE_STRERROR_S "" CACHE INTERNAL "")
  set(HAVE___XPG_STRERROR_R "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRERROR_R "1" CACHE INTERNAL "")

if (NOT HAVE_STRERROR_R OR HAVE___XPG_STRERROR_R)
  if (NOT HAVE___XPG_STRERROR_R AND NOT HAVE_STRERROR_S)
    message(FATAL_ERROR "strerror_r does not have an implementation that is \
thread-safe for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strerror-r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strerror-r.cmake)
endif ()
