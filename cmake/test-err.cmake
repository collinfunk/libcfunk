
include_guard(GLOBAL)

add_executable(test-err)

target_link_libraries(test-err PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-err PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-err.c
)

set_target_properties(test-err PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
