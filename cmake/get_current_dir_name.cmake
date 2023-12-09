
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("get_current_dir_name" "unistd.h" HAVE_GET_CURRENT_DIR_NAME)
endif ()

set(LIBCFUNK_DECLARE_GET_CURRENT_DIR_NAME "1" CACHE STRING "")

if (NOT HAVE_GET_CURRENT_DIR_NAME OR LIBCFUNK_REPLACE_GET_CURRENT_DIR_NAME)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getenv.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strdup.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getcwd.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/same_inode.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/get_current_dir_name.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-get_current_dir_name.cmake)
endif ()

