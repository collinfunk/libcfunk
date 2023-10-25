
include_guard(GLOBAL)

add_executable(test-isdigit)

target_link_libraries(test-isdigit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-isdigit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-isdigit.c
)

set_target_properties(test-isdigit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-isdigit" COMMAND test-isdigit)
