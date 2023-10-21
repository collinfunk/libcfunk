
include_guard(GLOBAL)

add_executable(test-usleep)

target_link_libraries(test-usleep PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-usleep PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-usleep.c
)

set_target_properties(test-usleep PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-usleep" COMMAND test-usleep)
