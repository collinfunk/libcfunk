
include_guard(GLOBAL)

# This check is now moved to 'libcfunk-init.cmake'.

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__func__.cmake)
endif ()

