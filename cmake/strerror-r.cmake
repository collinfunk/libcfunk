include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strerror_r" "string.h")
check_c_symbol("strerror_s" "string.h")
# GNU libc hides this pretty well in string.h, just check we can link.
check_c_function_links("__xpg_strerror_r")

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
