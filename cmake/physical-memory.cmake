
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/filename.cmake)

check_c_system_headers("sys/sysctl.h")
check_c_system_headers("windows.h")

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/physical-memory.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/physical-memory.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-physical-memory.cmake)
endif ()

