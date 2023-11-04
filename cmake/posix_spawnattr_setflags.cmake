
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawnattr_setflags" "spawn.h" HAVE_POSIX_SPAWNATTR_SETFLAGS)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWNATTR_SETFLAGS "1" CACHE INTERNAL "")

if (NOT HAVE_POSIX_SPAWNATTR_SETFLAGS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawnattr_setflags.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_spawnattr_setflags.cmake)
endif ()

