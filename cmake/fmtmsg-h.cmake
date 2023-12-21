
include_guard(GLOBAL)

# Generate <fmtmsg.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FMTMSG_H "1" CACHE STRING "")

check_include_file("fmtmsg.h" HAVE_FMTMSG_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fmtmsg-h.cmake)
endif ()

