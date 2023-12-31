
include_guard(GLOBAL)

add_executable(test-int-overflow)

target_link_libraries(test-int-overflow PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-int-overflow PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-int-overflow.c
)

set_target_properties(test-int-overflow PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-int-overflow" COMMAND test-int-overflow)
