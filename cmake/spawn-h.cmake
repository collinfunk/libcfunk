
include_guard(GLOBAL)

# Generate <spawn.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SPAWN_H "1" CACHE INTERNAL "")

check_include_file("spawn.h" HAVE_SPAWN_H)

if (HAVE_SPAWN_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "spawn.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("posix_spawnattr_t" POSIX_SPAWNATTR_T)
  check_type_size("posix_spawn_file_actions_t" POSIX_SPAWN_FILE_ACTIONS_T)
else ()
  set(HAVE_POSIX_SPAWNATTR_T "" CACHE INTERNAL "")
  set(HAVE_POSIX_SPAWN_FILE_ACTIONS_T CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-spawn-h.cmake)
endif ()

