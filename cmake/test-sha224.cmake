
include_guard(GLOBAL)

add_executable(test-sha224)

target_link_libraries(test-sha224 PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-sha224 PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-sha224.c
)

set_target_properties(test-sha224 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)