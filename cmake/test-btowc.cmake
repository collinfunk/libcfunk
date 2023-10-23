
include_guard(GLOBAL)

add_executable(test-btowc)

target_link_libraries(test-btowc PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-btowc PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-btowc.c
)

set_target_properties(test-btowc PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-btowc" COMMAND test-btowc)
