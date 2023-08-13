
include_guard(GLOBAL)

add_executable(test-sha256)

target_link_libraries(test-sha256 PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-sha256 PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-sha256.c
)

set_target_properties(test-sha256 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
