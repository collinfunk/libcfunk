
include_guard(GLOBAL)

add_executable(test-ffsll)

target_link_libraries(test-ffsll PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ffsll PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ffsll.c
)

set_target_properties(test-ffsll PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ffsll" COMMAND test-ffsll)
