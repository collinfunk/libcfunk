
include_guard(GLOBAL)

add_executable(test-sha512)

target_link_libraries(test-sha512 PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-sha512 PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-sha512.c
)

set_target_properties(test-sha512 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
