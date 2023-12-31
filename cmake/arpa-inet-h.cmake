
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/netinet-in-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <arpa/inet.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ARPA_INET_H "1" CACHE STRING "")

check_include_file("arpa/inet.h" HAVE_ARPA_INET_H)

if (HAVE_ARPA_INET_H)
  find_file(ARPA_INET_H_PATH NAMES "arpa/inet.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "arpa/inet.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-arpa-inet-h.cmake)
endif ()

