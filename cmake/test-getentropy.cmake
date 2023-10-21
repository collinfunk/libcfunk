
include_guard(GLOBAL)

add_executable(test-getentropy)

target_link_libraries(test-getentropy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getentropy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getentropy.c
)

set_target_properties(test-getentropy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getentropy" COMMAND test-getentropy)
