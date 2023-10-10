
include_guard(GLOBAL)

# Generate <signal.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SIGNAL_H "1" CACHE INTERNAL "")

check_include_file("signal.h" HAVE_SIGNAL_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-signal-h.cmake)
endif ()

