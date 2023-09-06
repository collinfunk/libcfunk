
include_guard(GLOBAL)

add_executable(test-program-name)

target_link_libraries(test-program-name PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-program-name PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-program-name.c
)

set_target_properties(test-program-name PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
