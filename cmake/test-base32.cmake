
include_guard(GLOBAL)

add_executable(test-base32)

target_link_libraries(test-base32 PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-base32 PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-base32.c
)

set_target_properties(test-base32 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
