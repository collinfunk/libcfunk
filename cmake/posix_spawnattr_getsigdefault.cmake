
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawnattr_getsigdefault" "spawn.h" HAVE_POSIX_SPAWNATTR_GETSIGDEFAULT)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWNATTR_GETSIGDEFAULT "1" CACHE STRING "")

if (NOT HAVE_POSIX_SPAWNATTR_GETSIGDEFAULT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawnattr_getsigdefault.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_spawnattr_getsigdefault.cmake)
endif ()

