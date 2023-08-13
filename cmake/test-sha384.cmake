
include_guard(GLOBAL)

add_executable(test-sha384)

target_link_libraries(test-sha384 PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-sha384 PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-sha384.c
)

set_target_properties(test-sha384 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
