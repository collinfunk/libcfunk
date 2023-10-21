
include_guard(GLOBAL)

add_executable(test-strmode)

target_link_libraries(test-strmode PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strmode PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strmode.c
)

set_target_properties(test-strmode PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

#add_test(NAME "test-strmode" COMMAND test-strmode)
