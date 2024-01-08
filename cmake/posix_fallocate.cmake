
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_FCNTL_H)
  check_symbol_exists("posix_fallocate" "fcntl.h" HAVE_POSIX_FALLOCATE)
endif ()

# TODO
if (NOT HAVE_POSIX_FALLOCATE)
  message(FATAL_ERROR "No implementation of 'posix_fallocate' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_fallocate.cmake)
endif ()

