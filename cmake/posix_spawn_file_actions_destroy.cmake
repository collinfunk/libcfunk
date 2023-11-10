
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawn_file_actions_destroy" "spawn.h" HAVE_POSIX_SPAWN_FILE_ACTIONS_DESTROY)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWN_FILE_ACTIONS_DESTROY "1" CACHE STRING "")

if (NOT HAVE_POSIX_SPAWN_FILE_ACTIONS_DESTROY OR LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_DESTROY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawn_file_actions_destroy.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_spawn_file_actions_destroy.cmake)
endif ()

