
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("symlink" "unistd.h" HAVE_SYMLINK)
endif ()

set(LIBCFUNK_DECLARE_SYMLINK "1" CACHE INTERNAL "")

if (NOT HAVE_SYMLINK)
  include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/symlink.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-symlink.cmake)
endif ()

