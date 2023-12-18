
include_guard(GLOBAL)

add_executable(test-tempnam)

target_link_libraries(test-tempnam PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-tempnam PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-tempnam.c
)

set_target_properties(test-tempnam PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-tempnam" COMMAND test-tempnam)
