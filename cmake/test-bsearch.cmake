
include_guard(GLOBAL)

add_executable(test-bsearch)

target_link_libraries(test-bsearch PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-bsearch PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-bsearch.c
)

set_target_properties(test-bsearch PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-bsearch" COMMAND test-bsearch)
