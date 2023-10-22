
include_guard(GLOBAL)

# Generate <errno.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ERRNO_H "1" CACHE INTERNAL "")

check_include_file("errno.h" HAVE_ERRNO_H)

if (HAVE_ERRNO_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "errno.h")
  check_type_size("error_t" ERROR_T)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "errno.h")
else ()
  set("error_t" HAVE_ERROR_T "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-errno-h.cmake)
endif ()

