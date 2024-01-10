
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-sys-shm-h)

target_link_libraries(test-sys-shm-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-shm-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-shm-h.c
)

set_target_properties(test-sys-shm-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-shm-h" COMMAND test-sys-shm-h)
