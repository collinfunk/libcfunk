
include_guard(GLOBAL)

add_executable(test-imaxdiv)

target_link_libraries(test-imaxdiv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-imaxdiv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-imaxdiv.c
)

set_target_properties(test-imaxdiv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-imaxdiv" COMMAND test-imaxdiv)
