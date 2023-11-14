
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawn" "spawn.h" HAVE_POSIX_SPAWN)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWN "1" CACHE STRING "")

if (NOT HAVE_POSIX_SPAWN OR LIBCFUNK_REPLACE_POSIX_SPAWN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawn.c
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawn_internal.h
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawn_internal.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_spawn1.cmake)
endif ()

