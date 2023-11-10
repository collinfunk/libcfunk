
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawn_file_actions_addclose" "spawn.h" HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCLOSE)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWN_FILE_ACTIONS_ADDCLOSE "1" CACHE STRING "")

if (NOT HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCLOSE OR LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_ADDCLOSE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawn_file_actions_addclose.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

