
include_guard(GLOBAL)

add_executable(test-copy-file)

target_link_libraries(test-copy-file PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-copy-file PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-copy-file.c
)

set_target_properties(test-copy-file PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
