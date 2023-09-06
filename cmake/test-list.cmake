
include_guard(GLOBAL)

add_executable(test-list)

target_link_libraries(test-list PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-list PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-list.c
)

set_target_properties(test-list PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
