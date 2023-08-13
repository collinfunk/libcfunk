
include_guard(GLOBAL)

add_executable(test-crc32)

target_link_libraries(test-crc32 PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-crc32 PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-crc32.c
)

set_target_properties(test-crc32 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
