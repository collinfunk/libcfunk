
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdarg-h.cmake)

# Generate <stdio.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDIO_H "1" CACHE STRING "")

check_include_file("stdio.h" HAVE_STDIO_H)
check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("io.h" HAVE_IO_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdio-h.cmake)
endif ()
