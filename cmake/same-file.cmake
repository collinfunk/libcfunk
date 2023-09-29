
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdbool-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/same-inode.cmake)

check_c_system_headers("windows.h")

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/same-file.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/same-file.c
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-same-file.cmake)
endif ()

