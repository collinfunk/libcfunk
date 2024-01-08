
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sched-h.cmake)

# Generate <spawn.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SPAWN_H "1" CACHE STRING "")

check_include_file("spawn.h" HAVE_SPAWN_H)

if (HAVE_SPAWN_H)
  find_file(SPAWN_H_PATH NAMES "spawn.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "spawn.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("posix_spawnattr_t" POSIX_SPAWNATTR_T)
  check_type_size("posix_spawn_file_actions_t" POSIX_SPAWN_FILE_ACTIONS_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-spawn-h.cmake)
endif ()

