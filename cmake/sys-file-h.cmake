
include_guard(GLOBAL)

# Generate <sys/file.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_FILE_H "1" CACHE STRING "")

check_include_file("sys/file.h" HAVE_SYS_FILE_H)

if (HAVE_SYS_FILE_H)
  find_file(SYS_FILE_H_PATH NAMES "sys/file.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-file-h.cmake)
endif ()
