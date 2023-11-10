
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawn_file_actions_adddup2" "spawn.h" HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2 "1" CACHE STRING "")

if (NOT HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2 OR LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawn_file_actions_adddup2.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

