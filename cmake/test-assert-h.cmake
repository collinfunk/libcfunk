
include_guard(GLOBAL)

add_executable(test-assert-h)

target_link_libraries(test-assert-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-assert-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-assert-h.c
)

set_target_properties(test-assert-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

#add_test(NAME "test-assert-h" COMMAND test-assert-h)
