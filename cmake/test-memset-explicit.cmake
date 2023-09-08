
include_guard(GLOBAL)

add_executable(test-memset-explicit)

target_link_libraries(test-memset-explicit PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-memset-explicit PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-memset-explicit.c
)

set_target_properties(test-memset-explicit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
