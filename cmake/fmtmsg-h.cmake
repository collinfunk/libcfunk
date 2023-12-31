
include_guard(GLOBAL)

# Generate <fmtmsg.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FMTMSG_H "1" CACHE STRING "")

check_include_file("fmtmsg.h" HAVE_FMTMSG_H)

if (HAVE_FMTMSG_H)
  find_file(FMTMSG_H_PATH NAMES "fmtmsg.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fmtmsg-h.cmake)
endif ()

