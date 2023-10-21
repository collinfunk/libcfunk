
include_guard(GLOBAL)

add_executable(test-clz)

target_link_libraries(test-clz PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-clz PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-clz.c
)

set_target_properties(test-clz PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-clz" COMMAND test-clz)
