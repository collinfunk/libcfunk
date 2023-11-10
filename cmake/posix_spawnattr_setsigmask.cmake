
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/spawn-h.cmake)

if (HAVE_SPAWN_H)
  check_symbol_exists("posix_spawnattr_setsigmask" "spawn.h" HAVE_POSIX_SPAWNATTR_SETSIGMASK)
endif ()

set(LIBCFUNK_DECLARE_POSIX_SPAWNATTR_SETSIGMASK "1" CACHE STRING "")

if (NOT HAVE_POSIX_SPAWNATTR_SETSIGMASK OR LIBCFUNK_REPLACE_POSIX_SPAWNATTR_SETSIGMASK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/posix_spawnattr_setsigmask.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_spawnattr_setsigmask.cmake)
endif ()

