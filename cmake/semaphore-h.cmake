
include_guard(GLOBAL)

# Generate <semaphore.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SEMAPHORE_H "1" CACHE STRING "")

check_include_file("semaphore.h" HAVE_SEMAPHORE_H)

if (HAVE_SEMAPHORE_H)
  find_file(SEMAPHORE_H_PATH NAMES "semaphore.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "semaphore.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-semaphore-h.cmake)
endif ()

