
include_guard(GLOBAL)

add_executable(test-strerror_r)

target_link_libraries(test-strerror_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strerror_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strerror_r.c
)

set_target_properties(test-strerror_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strerror_r" COMMAND test-strerror_r)
