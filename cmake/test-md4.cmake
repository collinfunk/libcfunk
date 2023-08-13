
include_guard(GLOBAL)

add_executable(test-md4)

target_link_libraries(test-md4 PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-md4 PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-md4.c
)

set_target_properties(test-md4 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
