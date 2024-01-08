
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_FCNTL_H)
  check_symbol_exists("posix_fadvise" "fcntl.h" HAVE_POSIX_FADVISE)
endif ()

# TODO
if (NOT HAVE_POSIX_FADVISE)
  message(FATAL_ERROR "No implementation of 'posix_fadvise' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_fadvise.cmake)
endif ()

