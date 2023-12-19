
include_guard(GLOBAL)

add_executable(test-fclose)

target_link_libraries(test-fclose PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fclose PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fclose.c
)

set_target_properties(test-fclose PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fclose" COMMAND test-fclose)
