
include_guard(GLOBAL)

add_executable(test-popcount)

target_link_libraries(test-popcount PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-popcount PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-popcount.c
)

set_target_properties(test-popcount PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
