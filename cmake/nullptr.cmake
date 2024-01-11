
include_guard(GLOBAL)

# The check for nullptr is placed in 'libcfunk-init'. This file just includes
# a test program.

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-nullptr.cmake)
endif ()
