
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("truncate" "unistd.h" HAVE_TRUNCATE)
endif ()

set(LIBCFUNK_DECLARE_TRUNCATE "1" CACHE STRING "")

if (NOT HAVE_TRUNCATE)
  include($CACHE{LIBCFUNK_MODULE_DIR}/ftruncate.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/truncate.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-truncate.cmake)
endif ()

