
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/same_inode.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/same_file.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/same_file.c
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-same_file.cmake)
endif ()

