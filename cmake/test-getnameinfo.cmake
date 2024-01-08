
include_guard(GLOBAL)

add_executable(test-getnameinfo)

target_link_libraries(test-getnameinfo PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getnameinfo PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getnameinfo.c
)

set_target_properties(test-getnameinfo PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getnameinfo" COMMAND test-getnameinfo)
