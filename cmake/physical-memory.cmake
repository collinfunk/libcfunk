
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/filename.cmake)

check_include_file("sys/sysctl.h" HAVE_SYS_SYSCTL_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/physical-memory.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/physical-memory.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-physical-memory.cmake)
endif ()

