
include_guard(GLOBAL)

add_executable(test-strlen)

target_link_libraries(test-strlen PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strlen PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strlen.c
)

set_target_properties(test-strlen PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strlen" COMMAND test-strlen)
