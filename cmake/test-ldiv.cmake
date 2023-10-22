
include_guard(GLOBAL)

add_executable(test-ldiv)

target_link_libraries(test-ldiv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ldiv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ldiv.c
)

set_target_properties(test-ldiv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ldiv" COMMAND test-ldiv)
