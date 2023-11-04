
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

# Generate <sys/socket.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_SOCKET_H "1" CACHE STRING "")

# Headers
check_include_file("sys/socket.h" HAVE_SYS_SOCKET_H)
check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("io.h" HAVE_IO_H)

# Check for Windows-specific headers and libraries.
if (HAVE_WINDOWS_H)
  check_include_files("windows.h;winsock2.h" HAVE_WINSOCK2_H)
  check_include_files("windows.h;ws2tcpip.h" HAVE_WS2TCPIP_H)
  find_library(WS2_32_LIBRARY "ws2_32" REQUIRED)
  target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "${WS2_32_LIBRARY}")
  list(APPEND CMAKE_REQUIRED_LIBRARIES "${WS2_32_LIBRARY}")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-socket-h.cmake)
endif ()

