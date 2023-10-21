
include_guard(GLOBAL)

add_executable(test-alloca)

target_link_libraries(test-alloca PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-alloca PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-alloca.c
)

set_target_properties(test-alloca PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-alloca" COMMAND test-alloca)
