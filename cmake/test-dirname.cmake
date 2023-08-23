
include_guard(GLOBAL)

add_executable(test-dirname)

target_link_libraries(test-dirname PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-dirname PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-dirname.c
)

set_target_properties(test-dirname PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
