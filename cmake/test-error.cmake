
include_guard(GLOBAL)

add_executable(test-error)

target_link_libraries(test-error PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-error PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-error.c
)

set_target_properties(test-error PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
