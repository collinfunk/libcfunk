
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawnp" "spawn.h" HAVE_POSIX_SPAWNP)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWNP "1" CACHE STRING "")

if (NOT HAVE_POSIX_SPAWNP OR LIBCFUNK_REPLACE_POSIX_SPAWNP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawnp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

