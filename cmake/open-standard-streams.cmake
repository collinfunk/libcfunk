
include_guard(GLOBAL)

# For _FILENO macros.
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/null-device.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/open-standard-streams.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/open-standard-streams.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-open-standard-streams.cmake)
endif ()

