
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-sys-statvfs-h)

target_link_libraries(test-sys-statvfs-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-statvfs-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-statvfs-h.c
)

set_target_properties(test-sys-statvfs-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-statvfs-h" COMMAND test-sys-statvfs-h)
