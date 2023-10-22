
include_guard(GLOBAL)

add_executable(test-lldiv)

target_link_libraries(test-lldiv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-lldiv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-lldiv.c
)

set_target_properties(test-lldiv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-lldiv" COMMAND test-lldiv)
