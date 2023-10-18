
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("readlink" "unistd.h" HAVE_READLINK)
else ()
  set(HAVE_READLINK "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_READLINK "1" CACHE INTERNAL "")

if (NOT HAVE_READLINK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/readlink.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-readlink.cmake)
endif ()
