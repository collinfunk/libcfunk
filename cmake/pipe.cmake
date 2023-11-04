
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("pipe" "unistd.h" HAVE_PIPE)
  check_symbol_exists("_pipe" "unistd.h" HAVE__PIPE)
endif ()

set(LIBCFUNK_DECLARE_PIPE "1" CACHE STRING "")

if (NOT HAVE_PIPE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/pipe.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-pipe.cmake)
endif ()

