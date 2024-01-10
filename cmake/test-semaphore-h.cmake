
include_guard(GLOBAL)

add_executable(test-semaphore-h)

target_link_libraries(test-semaphore-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-semaphore-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-semaphore-h.c
)

set_target_properties(test-semaphore-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-semaphore-h" COMMAND test-semaphore-h)
