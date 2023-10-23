
include_guard(GLOBAL)

add_executable(test-alloca-h)

target_link_libraries(test-alloca-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-alloca-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-alloca-h.c
)

set_target_properties(test-alloca-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-alloca-h" COMMAND test-alloca-h)
