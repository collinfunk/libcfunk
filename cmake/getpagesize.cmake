include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_c_symbol("getpagesize" "unistd.h")

set(LIBCFUNK_DECLARE_GETPAGESIZE "1" CACHE INTERNAL "")

if (NOT HAVE_GETPAGESIZE)
  if (NOT HAVE_WINDOWS_H)
    message(FATAL_ERROR "Unsupported operating system")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getpagesize.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getpagesize.cmake)
endif ()

