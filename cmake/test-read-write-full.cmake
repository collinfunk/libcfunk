
include_guard(GLOBAL)

add_executable(test-read-write-full)

target_link_libraries(test-read-write-full PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-read-write-full PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-read-write-full.c
)

set_target_properties(test-read-write-full PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
