
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawnattr_getpgroup" "spawn.h" HAVE_POSIX_SPAWNATTR_GETPGROUP)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWNATTR_GETPGROUP "1" CACHE STRING "")

if (NOT HAVE_POSIX_SPAWNATTR_GETPGROUP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawnattr_getpgroup.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_spawnattr_getpgroup.cmake)
endif ()

