
include_guard(GLOBAL)

add_executable(test-imaxabs)

target_link_libraries(test-imaxabs PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-imaxabs PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-imaxabs.c
)

set_target_properties(test-imaxabs PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-imaxabs" COMMAND test-imaxabs)
