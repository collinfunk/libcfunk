
include_guard(GLOBAL)

add_executable(test-shutdown)

target_link_libraries(test-shutdown PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-shutdown PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-shutdown.c
)

set_target_properties(test-shutdown PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-shutdown" COMMAND test-shutdown)
