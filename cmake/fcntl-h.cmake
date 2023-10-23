
include_guard(GLOBAL)

# Generate <fcntl.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FCNTL_H "1" CACHE INTERNAL "")

check_include_file("fcntl.h" HAVE_FCNTL_H)
check_include_file("io.h" HAVE_IO_H)

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_CREAT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FCNTL "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_OPEN "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fcntl-h.cmake)
endif ()

