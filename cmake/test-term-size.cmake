
include_guard(GLOBAL)

add_executable(test-term-size)

target_link_libraries(test-term-size PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-term-size PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-term-size.c
)

set_target_properties(test-term-size PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)